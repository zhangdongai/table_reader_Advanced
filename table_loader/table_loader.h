#ifndef TABLELOADER_TABLE_LOADER_FILE_H
#define TABLELOADER_TABLE_LOADER_FILE_H

#include "common/base.h"

#include <string>
#include <vector>

namespace table_loader {

class TableLoader {
public:
    bool init();
    /**
    * @brief Load single table
    * @param prefix. The prefix of table, such as 'TableTemplate'
    * @param filename. Table file path
    */
    bool read(const std::string& prefix, const std::string& filename);

    SINGLETION_DECLARE(TableLoader);
};

}  // namespace table_loader

#define TABLE_READER(TABLE_NAME, FILE_NAME)                       \
    if (!TableLoader::instance()->read(#TABLE_NAME, FILE_NAME)) { \
        return false;                                             \
    }

#endif // TABLELOADER_TABLE_LOADER_FILE_H