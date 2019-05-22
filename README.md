## Description
Given a table with several rows and column, fields in the same column are in the same type. This program is designed to read this kind table. It supports int, float, string, and it's easy to add new data type. It also supports customized data type(hasn't been implemented well).

Please refer to table example [table_template.txt](https://github.com/zhangdongai/table_reader_Advanced/blob/master/config/table_template.txt).

## Dependency
boost

`sudo apt-get install libboost-all-dev`

gtest

please refer to [gtest installation](https://github.com/zhangdongai/objectpool/blob/master/objectpool/install_gtest.sh) to install gtest

## Supported types
```"INT"-->int
"FLOAT"-->float
"STRING"-->string
"INTARRAY"-->array of int
"FLOATARRAY"-->array of float
"CUSTOM"-->customized type
```
## How to use
main.cpp shows how to get a specified Line object.
Take table_template.txt as an example, use `GetTableTemplateById` or `GetTableTemplateByIndex` to get Line object, such as
```
const std::shared_ptr<line::Line> line = GetTableTemplateById(1);
```
Line object contains all the fields in different types.
Users could get a field by its title, such as:
```
const auto intfield = line->get<int32_t>("Idata");
```
'Idata' is the title in the first line of the table file. The real data type of variable `intfield` is `std::shared_ptr<field::Field<int32_t>>`.

As to array, use below code to access array elements:
```
const auto afield = line->get<custom::Array<int32_t>>("Items");
if (!afield) {
    ASSERT_LOG(false, "cannot get field 'Idata'");
}
std::cout << "Adata = " << afield->get_data()[0] << std::endl;
```

## Add new table
It's very convinent to add a new table. Users just need to add three code line. The steps are:
1. `line_logic/line_get.h`, add `TABLE_GET_DECL(TableNew);`
2. `line_logic/line_get.cpp`, add `TABLE_GET_IMPL(TableNew);`
3. `table_loader/table_loader.cpp`, in function `Init`, add `TABLE_READER(TableNew, "./config/table_new.txt");`
And then, users could use `GetTableNewById` and `GetTableNewByIndex` to access Line objects.
