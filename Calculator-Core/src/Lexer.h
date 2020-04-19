#pragma once
#include "Expression.h"
#include "Expressions/AddExpression.h"
#include "Expressions/SubExpression.h"
#include "Expressions/MultiplyExpression.h"
#include "Expressions/DivideExpression.h"
#include "Expressions/ConstantExpression.h"
#include "Expressions/VariableExpression.h"

namespace clc
{

	class Lexer
	{
	public:
		ExpressionPtr BuildExpression(const std::vector<std::string>& tokens) const;
		ExpressionPtr BuildExpression(const std::string& expr) const;
		ExpressionPtr BuildExpression(const char** tokens, size_t length);

	private:
		ExpressionPtr CreateExprRecursive(const std::string_view& expr) const;
		bool IsNumericString(const std::string_view& str) const;
	};

}