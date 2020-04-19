#include "Expressions/AddExpression.h"
#include "Expressions/VariableExpression.h"
#include "Expressions/ConstantExpression.h"
#include "ExpressionContext.h"
#include "Lexer.h"

#include <iostream>

int main(int argc, char** argv)
{
	clc::ExpressionContext context;
	context.CreateConstantVariable("PI", 3.14159);

	clc::Lexer lex;
	clc::ExpressionPtr expr;
	if (argc > 1)
		expr = lex.BuildExpression((const char**)(argv + 1), (size_t)(argc) - 1);
	else
		expr = lex.BuildExpression("PI + 4.5");
	std::cout << "Evaluating... " << expr->ToString(context) << " = " << expr->Evaluate(context)->ToString(context) << std::endl;

	return 0;
}