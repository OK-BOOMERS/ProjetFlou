//
// Created by pisel on 28/01/2020.
//

#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core{
    template <class T>
    class BinaryExpressionModelTest: public Expression<T>, public BinaryExpression<T>{
    private:
        Expression<T>* left;
        Expression<T>* right;
        BinaryExpression<T>* ope;



    public:
        BinaryExpressionModelTest(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* ope);

        virtual ~BinaryExpressionModelTest();
        virtual BinaryExpression<T>* getOperateur();
        virtual T evaluate()const;
        virtual T evaluate(Expression<T>* l,Expression<T>* r)const;
    };

    template<class T>
    T BinaryExpressionModelTest<T>::evaluate() const{
        if (left != nullptr && right != nullptr)
            return evaluate(left, right);
    }

    template<class T>
    BinaryExpressionModelTest<T>::BinaryExpressionModelTest(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* ope):left(left), right(right), ope(ope) {}

    template<class T>
    BinaryExpressionModelTest<T>::~BinaryExpressionModelTest() {
    }

    template<class T>
    T BinaryExpressionModelTest<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        if (ope != nullptr)
            return ope->evaluate(l, r);
    }

    template<class T>
    BinaryExpression<T> *BinaryExpressionModelTest<T>::getOperateur() {
        return this->ope;
    }

}

#endif //BINARYEXPRESSIONMODEL_H
