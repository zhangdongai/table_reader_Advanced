#include <gtest/gtest.h>

#include "table_loader/table_loader.h"
#include "common/factory/container_factory.h"
#include "common/factory/field_factory.h"
#include "custom/custom_array.h"
#include "field/field_impl.h"
#include "line_logic/line_impl.h"
#include "line_logic/line_get.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    DEBUG_LOG("int comlog end!");

    common::factory::ContainerFactory::instance()->register_all();
    common::factory::FieldFactory::instance()->register_all();
    bool init_ret = table_loader::TableLoader::instance()->init();
    ASSERT_LOG(init_ret, "data streamer init failed!");

    const std::shared_ptr<line::Line> line = GetTableTemplateById(1);
    if (!line) {
      ASSERT_LOG(false, "cannot get field 'Idata'");
    }

    // std::shared_ptr<field::Field<int32_t>>
    const auto intfield = line->get<int32_t>("Idata");
    if (!intfield) {
        ASSERT_LOG(false, "cannot get field 'Idata'");
    }

    std::cout << "Idata = " << intfield->get_data() << std::endl;

    // std::shared_ptr<field::Field<float>>
    const auto ffield = line->get<float>("Fdata");
    if (!ffield) {
        ASSERT_LOG(false, "cannot get field 'Idata'");
    }

    std::cout << "Fdata = " << ffield->get_data() << std::endl;

    // std::shared_ptr<field::Field<custom::Array<int32_t>>>
    const auto afield =
        line->get<custom::Array<int32_t>>("Items");
    if (!afield) {
        ASSERT_LOG(false, "cannot get field 'Idata'");
    }

    std::cout << "Adata = " << afield->get_data()[0] << std::endl;

    //以下内容会输出到屏幕上
    DEBUG_LOG("run GTEST finally!");
    return RUN_ALL_TESTS();
}