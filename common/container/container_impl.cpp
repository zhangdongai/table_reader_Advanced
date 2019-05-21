#include "common/container/container_impl.h"

#include "common/data_type/datatype_parser.h"
#include "common/log.h"

namespace common {
namespace container {

void ContainerImpl::load_datatype(const std::string& datatype_cont) {
    std::vector<std::string> datatype_str_con;
    std::vector<DataType> datatype_con;
    utils::string_split(datatype_cont, &datatype_str_con);
    DataTypeParser::instance()->parse_datatype(
        datatype_str_con, &datatype_con);

    datatype_con_ = datatype_con;
}

void ContainerImpl::load_title(const std::string& title_cont) {
    std::vector<std::string> title_con;
    std::vector<DataType> datatype_con;
    utils::string_split(title_cont, &title_con);
    int32_t index = 0;
    for (const auto& e : title_con) {
        datatitle_con_[e] = index;
        ++index;
    }
}

void ContainerImpl::load_line(const std::string& line) {
    std::vector<std::string> dataitem_con;
    utils::string_split(line, &dataitem_con);

    ASSERT_LOG((datatype_con_.size() == dataitem_con.size()),
        "length of datatype is not equal to length of data!");

    dataitem_con_ = dataitem_con;
    std::shared_ptr<line::Line> ptr = create_line();
    if (ptr) {
        ptr->parse(dataitem_con);
    }
}

int32_t ContainerImpl::get_field_index(const std::string& title_name) {
    if (datatitle_con_.find(title_name) != datatitle_con_.end()) {
        return datatitle_con_.at(title_name);
    }
    return -1;
}


std::shared_ptr<line::Line> ContainerImpl::create_line() {
    std::shared_ptr<Line> ptr(new Line(this));
    content_con_raw_.push_back(ptr);
    int id = -1;
    TRY_ENTRY
    id = std::stoi(dataitem_con_[0].c_str());
    ASSERT_LOG((id >=0), "id must be more than or equal to 0");
    CATCH_EXIT
    content_con_indexed_[id] = ptr;
    return ptr;
}

std::shared_ptr<Line> ContainerImpl::get_line_by_id(const int id) const {
    if (content_con_indexed_.find(id) != content_con_indexed_.end()) {
        return content_con_indexed_.at(id);
    }
    return nullptr;
}

std::shared_ptr<Line> ContainerImpl::get_line_by_index(
    const int index) const {
    if (index >=0 && index < content_con_raw_.size()) {
        return content_con_raw_[index];
    }
    return nullptr;
}

}  // namespace common
}  // namespace container