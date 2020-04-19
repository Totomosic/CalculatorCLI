#pragma once
#include <vector>
#include <memory>
#include <string>

namespace clc
{

	class ExpressionContext;

	class Expression;
	using ExpressionPtr = std::shared_ptr<Expression>;
	
	template<typename T, typename ... Args>
	inline ExpressionPtr CreateExpr(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	class Expression
	{
	private:
		std::vector<ExpressionPtr> m_SubExpressions;

	public:
		virtual ~Expression() = default;
		virtual ExpressionPtr Evaluate(const ExpressionContext& context) const = 0;
		virtual std::string ToString(const ExpressionContext& context) const = 0;
		virtual bool HasNumericValue(const ExpressionContext& context) const = 0;
		virtual double GetNumericValue(const ExpressionContext& context) const = 0;

	protected:
		void AddExpression(const ExpressionPtr& expr);
		const ExpressionPtr& GetExpression(int index) const;
	};

}