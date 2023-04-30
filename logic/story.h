#ifndef STORY_H
#define STORY_H

#include <QString>

class Story
{
private:
    QString imgPath;
    QString caption;
    QString publisherID;

public:
    Story();

    QString getImgPath() const;
    void setImgPath(const QString &value);

    QString getCaption() const;
    void setCaption(const QString &value);

    QString getPublisherID() const;
    void setPublisherID(const QString &value);
};

#endif // STORY_H
