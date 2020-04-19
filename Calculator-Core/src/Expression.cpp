#include "Expression.h"
#include "assert.h"

namespace clc
{

	void Expression::AddExpression(const ExpressionPtr& expr)
	{
		m_SubExpressions.push_back(expr);
	}

	const ExpressionPtr& Expression::GetExpression(int index) const
	{
		CLC_ASSERT(index >= 0 && index < m_SubExpressions.size(), "Invalid expression index");
		return m_SubExpressions[index];
	}

}
