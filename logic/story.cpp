#include "story.h"

Story::Story()
{
}

QString Story::getImgPath() const
{
    return imgPath;
}

void Story::setImgPath(const QString &value)
{
    imgPath = value;
}

QString Story::getCaption() const
{
    return caption;
}

void Story::setCaption(const QString &value)
{
    caption = value;
}

QString Story::getPublisherID() const
{
    return publisherID;
}

void Story::setPublisherID(const QString &value)
{
    publisherID = value;
}
