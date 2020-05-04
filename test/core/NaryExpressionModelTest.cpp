#include <gtest/gtest.h>
#include "../../src/core/UnaryExpressionModel.h"
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/IsTriangle.h"

using namespace fuzzy;

TEST(NaryExpressionModel,evaluate){

    core::ValueModel<float> food(8);
    core::ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    core::UnaryExpressionModel<float> e1(&food,&excellent);
    core::UnaryExpressionModel<float> e2(&service,&bad);
    core::UnaryExpressionModel<float> e3(&service,&excellent);


    
}