#include <gtest/gtest.h>
#include "../../src/core/UnaryExpressionModel.h"
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/IsTriangle.h"
#include "../../src/fuzzy/AndMin.h"
#include "../../src/core/NaryExpressionModel.h"

using namespace fuzzy;

TEST(NaryExpressionModel,evaluate){

    core::ValueModel<float> food(8);
    core::ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    core::UnaryExpressionModel<float> e1(&food,&excellent);
    core::UnaryExpressionModel<float> e2(&service,&bad);
    core::UnaryExpressionModel<float> e3(&service,&excellent);

    AndMin<float> andmin;
    std::vector<core::Expression<float>*> ops;
    ops.push_back(&e1);
    ops.push_back(&e2);
    ops.push_back(&e3);

    core::NaryExpressionModel<float> naryExpressionModel(ops, &andmin);
    ASSERT_EQ(naryExpressionModel.evaluate(),0.5f);


}