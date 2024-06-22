#include "GrayScaleComand.h"

GrayScaleComand::GrayScaleComand(Vector<Polymorphic_Ptr<Image>>& data):Comand(data)
{
}

void GrayScaleComand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Polymorphic_Ptr<Image>>(data);

    for (unsigned i = 0; i < data.getSize(); i++)
    {
        data[i]->grayscale();
    }
}
void GrayScaleComand::undo()
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

Comand* GrayScaleComand::clone() const
{
    return new GrayScaleComand(*this);
}
