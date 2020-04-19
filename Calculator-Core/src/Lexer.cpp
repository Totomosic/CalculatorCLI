#include "Lexer.h"
#include "stringutils.h"
#include <iostream>

namespace clc
{

	ExpressionPtr Lexer::BuildExpression(const std::vector<std::string>& tokens) const
	{
		std::string expression;
		std::vector<std::string> cleanedTokens = tokens;
		for (std::string& s : cleanedTokens)
		{
			clc::remove_all(s, " \r\t\n");
			expression += s;
		}
		return CreateExprRecursive(expression);
	}

	ExpressionPtr Lexer::BuildExpression(const std::string& expr) const
	{
		return BuildExpression(split(expr, ' '));
	}

	ExpressionPtr Lexer::BuildExpression(const char** tokens, size_t length)
	{
		std::vector<std::string> tks;
		tks.reserve(length);
		for (size_t i = 0; i < length; i++)
			tks.push_back(tokens[i]);
		return BuildExpression(tks);
	}

	ExpressionPtr Lexer::CreateExprRecursive(const std::string_view& expr) const
	{
		size_t operatorPos = expr.find_last_of("+-");
		if (operatorPos != std::string::npos)
		{
			ExpressionPtr left = CreateExprRecursive(expr.substr(0, operatorPos));
			ExpressionPtr right = CreateExprRecursive(expr.substr(operatorPos + 1));
			char op = expr[operatorPos];
			switch (op)
			{
			case '+':
				return CreateExpr<AddExpression>(left, right);
			case '-':
				return CreateExpr<SubExpression>(left, right);
			case '*':
				return CreateExpr<MultiplyExpression>(left, right);
			case '/':
				return CreateExpr<DivideExpression>(left, right);
			}
		}
		else
		{
			operatorPos = expr.find_last_of("*/");
			if (operatorPos != std::string::npos)
			{
				ExpressionPtr left = CreateExprRecursive(expr.substr(0, operatorPos));
				ExpressionPtr right = CreateExprRecursive(expr.substr(operatorPos + 1));
				char op = expr[operatorPos];
				switch (op)
				{
				case '+':
					return CreateExpr<AddExpression>(left, right);
				case '-':
					return CreateExpr<SubExpression>(left, right);
				case '*':
					return CreateExpr<MultiplyExpression>(left, right);
				case '/':
					return CreateExpr<DivideExpression>(left, right);
				}
			}
			else
			{
				if (IsNumericString(expr))
				{
					return CreateExpr<ConstantExpression>(std::stod(std::string(expr)));
				}
				else
				{
					return CreateExpr<VariableExpression>(std::string(expr));
				}
			}
		}
		return CreateExpr<ConstantExpression>(0.0);
	}

	bool Lexer::IsNumericString(const std::string_view& str) const
	{
		int decimalCount = 0;
		int index = 0;
		for (char c : str)
		{
			if (c == '.')
			{
				if (decimalCount == 0)
					decimalCount++;
				else
					return false;
			}
			else if (c == '-' && index != 0)
				return false;
			else if (!std::isdigit((unsigned char)c))
				return false;
			index++;
		}
		return true;
	}

}
