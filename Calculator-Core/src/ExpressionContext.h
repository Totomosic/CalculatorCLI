#pragma once
#include <unordered_map>
#include "Expression.h"

namespace clc
{

	class ExpressionContext
	{
	private:
		std::unordered_map<std::string, ExpressionPtr> m_VariableMap;

	public:
		bool HasVariable(const std::string& varname) const;
		ExpressionPtr GetVariable(const std::string& varname) const;

		void CreateConstantVariable(const std::string& varname, double value);

	};

}