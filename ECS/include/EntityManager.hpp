#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <memory>
#include <vector>

#include "IEntity.hpp"

namespace ecs
{
    using Entity_Ptr = std::unique_ptr<IEntity>;

    class EntityManager
    {
        public:
            template<typename T, typename... ARGS>
            T* CreateEntity(ARGS&&... args)
            {
                EntityId entityid = this->GetEntityId();

                IEntity* entity = new T(entityid, std::forward<ARGS>(args)...);
                entities_.push_back(Entity_Ptr(entity) );

                return static_cast<T*>(entity);
            }

            template<typename T>
            void DestroyEntity(EntityId entityid)
            {
                for(auto e = entities_.begin(); e != entities_.end(); e++)
                {
                    if(e->get()->GetEntityId() == entityid)
                    {
                        entities_.erase(e);
                    }
                }
            }

            void DestroyAllEntities()
            {
                entities_.clear();
            }

        private:
            EntityId GetEntityId()
            {
                return entities_.size() + 1;
            }

            std::vector<Entity_Ptr> entities_;
    };
}

#endif // ENTITY_MANAGER_HPP
