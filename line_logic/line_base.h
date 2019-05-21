#ifndef LINE_LOGIC_LINE_BASE_H
#define LINE_LOGIC_LINE_BASE_H

#include <string>
#include <vector>

namespace line {

class LineBase {
public:
    /**
    * @brief 接口函数。从TableContainer中读取每一列的数据项，要求子类重写该函数
    *        并根据数据情况读取数据项
    * @exception handle 子类函数中调用load_data加载数据，load_data函数中会捕获
    *        std::exception异常。出现异常后会记录日志并返回false。
    *        要求子类实现load_content时判断load_data的返回值，进行错误日志记录
    *        和assert。
    *        如果出现异常或返回值为false，说明代码逻辑和数据表格式不对应
    */
    virtual void parse(const std::vector<std::string>&) = 0;
};

}  // namespace line

#endif // LINE_LOGIC_LINE_BASE_H