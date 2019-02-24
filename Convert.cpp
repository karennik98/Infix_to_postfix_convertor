#include "Convert.h"
#include "Exception.h"

void Convert::infix_to_postfix()
{
	unsigned i = 0;
	while (i <= m_Str.size())
	{
		if (is_operand(m_Str[i]))
			m_stream << m_Str[i];
		else if (is_operator(m_Str[i]))
		{
			if (m_opStack.empty() || is_parenthes(m_opStack.top()))
			{
				m_opStack.push(m_Str[i]);
			}
			else if (op_value(m_opStack.top()) >= op_value(m_Str[i]))
			{
				m_stream << m_opStack.top();
				m_opStack.pop();
				m_opStack.push(m_Str[i]);
			}
			else
			{
				m_opStack.push(m_Str[i]);
			}
		}
		else if (is_parenthes(m_Str[i]) && m_Str[i] == static_cast<char>(Parenthes::Open))
			m_opStack.push(m_Str[i]);
		else if (is_parenthes(m_Str[i]) && m_Str[i] == static_cast<char>(Parenthes::Close))
		{
			while (!m_opStack.empty() && m_opStack.top() != static_cast<char>(Parenthes::Open))
			{
				m_stream << m_opStack.top();
				m_opStack.pop();
			}
			m_opStack.pop();
		}
		i++;
	}
	while (!m_opStack.empty())
	{
		m_stream << m_opStack.top();
		m_opStack.pop();
	}
}
const std::ostringstream& Convert::getStream()const
{
	return m_stream;
}
bool Convert::is_operator(const char& ch)const
{
	return
		(
			ch == static_cast<char>(Operators::Add) ||
			ch == static_cast<char>(Operators::Deegre) ||
			ch == static_cast<char>(Operators::Divide) ||
			ch == static_cast<char>(Operators::Minus) ||
			ch == static_cast<char>(Operators::Plus)
			);
}
bool Convert::is_operand(const char& ch)const
{
	return (!is_operator(ch) && !is_parenthes(ch));
}
bool Convert::is_parenthes(const char& ch)const
{
	return (ch == static_cast<char>(Parenthes::Open) || ch == static_cast<char>(Parenthes::Close));
}
int Convert::op_value(const char& ch)const
{
	switch (ch)
	{
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	case'^':
		return 3;
	default:
		throw WrongItem("Convert.cpp", "ch_value()", 73);
	}
}