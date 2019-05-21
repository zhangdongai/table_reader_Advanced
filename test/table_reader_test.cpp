#include <gtest/gtest.h>

#include "common/factory/container_factory.h"

/*
class TableReaderTest : public ::testing::Test {
public:
    virtual void SetUp() {
    }
};

//下面的TEST测试按照ID获取数据表，并和数据表中的配置数据进行对比
TEST_F(TableReaderTest, GetTableById) {
    //获取planning数据表的特定id的数据
    std::shared_ptr<TablePlanningTable> table_ptr = GetTablePlanningById(1);
    ASSERT_NE(table_ptr, nullptr);
    EXPECT_EQ(table_ptr->idata_, 14);
    EXPECT_FLOAT_EQ(table_ptr->fdata_, 10.4f);
    EXPECT_EQ(table_ptr->adata_[0], 312);
    EXPECT_EQ(table_ptr->adata_[1], 534);
    EXPECT_EQ(table_ptr->adata_[2], 12);
    const Planning& planning_data = table_ptr->planning_data_;
    EXPECT_EQ(planning_data.type_, 1);
    EXPECT_EQ(planning_data.time_interval_, 10);
    EXPECT_FLOAT_EQ(planning_data.distance_, 50.0f);
}

//下面的TEST测试按照索引获取数据表，并和数据表中的配置数据进行对比
TEST_F(TableReaderTest, GetTableByIndex) {
    //获取planning数据表的第一行
    std::shared_ptr<TablePlanningTable> table_ptr = GetTablePlanningByIndex(0);
    ASSERT_NE(table_ptr, nullptr);
    EXPECT_EQ(table_ptr->idata_, 14);
    EXPECT_FLOAT_EQ(table_ptr->fdata_, 10.4f);
    EXPECT_EQ(table_ptr->adata_[0], 312);
    EXPECT_EQ(table_ptr->adata_[1], 534);
    EXPECT_EQ(table_ptr->adata_[2], 12);
    const Planning& planning_data = table_ptr->planning_data_;
    EXPECT_EQ(planning_data.type_, 1);
    EXPECT_EQ(planning_data.time_interval_, 10);
    EXPECT_FLOAT_EQ(planning_data.distance_, 50.0f);
}
*/