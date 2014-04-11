#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <vector>
#include "../Graphics/GraphicsComponent.h"
#include "../Physics/PhysicsComponent.h"
#include "../Utils/bbox.h"

namespace jr
{

using std::vector;

class Entity
{
	public:
    Entity(GraphicsComponent* g, PhysicsComponent* p);
    virtual ~Entity();

    virtual void update() = 0;
    bbox<float> getBounds();
    PhysicsComponent* getPhysicsComponent();
    bool shouldDelete();
    bool isParent();
    vector<Entity*>& getChildren();
    void setDrawer(Drawer* d);

  protected:
    GraphicsComponent* gcomp;
    PhysicsComponent* pcomp;

    void scheduleDeletion(); 
    void instantiate(Entity* child);
    void setPriority(int p);

	private:
    bool deleteMe;
    vector<Entity*> children;
};

}
#endif
