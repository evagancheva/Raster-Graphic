#include "RotateRightComand.h"

RotateRightComand::RotateRightComand(Vector<Polymorphic_Ptr<Image>>& data) :Comand(data)
{
}

void RotateRightComand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Polymorphic_Ptr<Image>>(data);

    for (unsigned i = 0; i < data.getSize(); i++)
    {
        data[i]->rotateRight();
    }
}
void RotateRightComand::undo()
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

Comand* RotateRightComand::clone() const
{
    return new RotateRightComand(*this);
}

RotateRightComand::~RotateRightComand()
{
    if (!snapshot) {
        delete snapshot;
    }
}