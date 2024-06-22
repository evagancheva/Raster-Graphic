#include "MonochromeComand.h"


MonochromeComand::MonochromeComand(Vector<Polymorphic_Ptr<Image>>& data) :Comand(data)
{
}

void MonochromeComand::execute()
{
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new Vector<Polymorphic_Ptr<Image>>(data);

    for (unsigned i = 0; i < data.getSize(); i++)
    {
        data[i]->makeMonochrome();
    }
}
void MonochromeComand::undo()
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

Comand* MonochromeComand::clone() const
{
    return new MonochromeComand(*this);
}

MonochromeComand::~MonochromeComand()
{
    if (!snapshot) {
        delete snapshot;
    }
}
