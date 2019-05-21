#include "table_loader/table_loader.h"

#include <sstream>
#include <iostream>
#include <fstream>

#include "common/data_type/datatype_parser.h"
#include "common/factory/container_factory.h"
#include "common/log.h"

namespace table_loader {

using common::container::ContainerImpl;
using common::factory::ContainerFactory;
using ContainerPtr = std::shared_ptr<ContainerImpl>;

TableLoader::TableLoader() {}

bool TableLoader::init() {
    //数据表读取代码放在此处
    TABLE_READER(TableTemplate, "./config/table_template.txt");

    return true;
}

bool TableLoader::read(const std::string& prefix,
                        const std::string& filename) {
    DEBUG_LOG("begin to load file %s.", filename.c_str());
    std::ifstream ifs(filename.c_str(), std::ios::in);
    if (!ifs.is_open()) {
        ERROR_LOG("cannot load file %s.", filename.c_str());
        return false;
    }
    
    ContainerPtr container = 
        ContainerFactory::instance()->get_container_ptr(prefix);
    if (!container) {
        ERROR_LOG("cannot get table container %s.", prefix.c_str());
        ifs.close();
        return false;
    }

    //读取第一行，第一行是数据的title
    std::string title_line;
    std::getline(ifs, title_line);
    container->load_title(title_line);

    //读取第二行，第二行是数据类型
    std::string datatype_line;
    std::getline(ifs, datatype_line);
    container->load_datatype(datatype_line);

    //开始依次读取数据行
    std::string line;
    while (1) {
        std::string line;
        if (!std::getline(ifs, line)) {
            break;
        }
        container->load_line(line);
    }

    DEBUG_LOG("load file %s successfully.", filename.c_str());

    ifs.close();
    return true;
}

}  // namespace table_loader