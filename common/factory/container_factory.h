#ifndef COMMON_FACTORY_CONTAINER_FACTORY_FILE_H
#define COMMON_FACTORY_CONTAINER_FACTORY_FILE_H

#include <unordered_map>

#include "common/base.h"
#include "common/container/container_impl.h"

namespace common {
namespace factory {

using common::container::ContainerImpl;
using ContainerPtr = std::shared_ptr<ContainerImpl>;

class ContainerFactory {
public:
    /**
    * @brief Register all Containers
    *        Newly added table must register Container itself.
    */
    void register_all();

    /**
    * @brief Get Container pointer via the prefix of table
    * @param prefix. Such as 'TablePlanning'
    * @return ContainerPtr if found, or nullptr
    */
    ContainerPtr get_container_ptr(const std::string& prefix);

private:
    void register_con(const std::string& name, ContainerPtr container);
    
    std::unordered_map<std::string, ContainerPtr> container_con_;

    SINGLETION_DECLARE(ContainerFactory);
};

}  // namespace factory
}  // namespace common

#define REGISTER_CONTAINER(NAME) \
    ContainerFactory::instance()->register_con(#NAME, ContainerPtr(new ContainerImpl));

#endif // COMMON_FACTORY_CONTAINER_FACTORY_FILE_H