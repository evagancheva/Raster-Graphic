#include "RotateLeftComand.h"


RotateLeftComand::RotateLeftComand(Vector<Polymorphic_Ptr<Image>>& data) :Comand(data)
{
}

void RotateLeftComand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Polymorphic_Ptr<Image>>(data);

    for (unsigned i = 0; i < data.getSize(); i++)
    {
        data[i]->rotateLeft();
    }
}
void RotateLeftComand::undo()
{
    if (snapshot) {
        for (size_t i = 0; i < snapshot->getSize(); i++)
        {
            data[i] = (*snapshot)[i];
        }
    }
    delete snapshot;
    snapshot = nullptr;
}

Comand* RotateLeftComand::clone() const
{
    return new RotateLeftComand(*this);
}

RotateLeftComand::~RotateLeftComand()
{
    if (!snapshot) {
        delete snapshot;
    }
}
