## Description
Given a table with several rows and column, fields in the same column are in the same type. This program is designed to read this kind table. It supports int, float, string, and it's easy to add new data type. It also supports customized data type(hasn't been implemented well).

Please refer to table example [table_template.txt](https://github.com/zhangdongai/table_reader_Advanced/blob/master/config/table_template.txt).

## Dependency
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

## Add new table

## Add new type
