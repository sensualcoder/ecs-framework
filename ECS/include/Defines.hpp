#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <cstddef>

namespace ecs
{
    using TypeId = size_t;
    
    using ComponentId = TypeId;
    using ComponentTypeId = TypeId;
    
    using EntityId = TypeId;
    
    using SystemId = TypeId;
    using SystemTypeId = TypeId;
}

#endif
