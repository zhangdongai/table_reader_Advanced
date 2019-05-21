#include "common/factory/container_factory.h"

namespace common {
namespace factory {

ContainerFactory::ContainerFactory() {}

void ContainerFactory::register_all() {
    REGISTER_CONTAINER(TableTemplate);
}

void ContainerFactory::register_con(const std::string& name, ContainerPtr container) {
    container_con_[name] = container;
}

ContainerPtr ContainerFactory::get_container_ptr(const std::string& name) {
    if (container_con_.find(name) != container_con_.end()) {
        return container_con_[name];
    }
    return nullptr;
}

}  // namespace common
}  // namespace factory