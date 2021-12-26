#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Object.h"
#include "AnimationChannel.h"

namespace gameplay
{

class Animation : public Object
{
public:

    Animation(void);
    virtual ~Animation(void);
    virtual unsigned int getTypeId(void) const;
    virtual const char* getElementName(void) const;
    virtual void writeBinary(FILE* file);
    virtual void writrText(FILE* file);

    void add(AnimationChannel* animationChannel);
    void remove(AnimationChannel* animationChannel);
    unsigned int getAnimationChannelCount() const;

    AnimationChannel* getAnimationChannel(unsigned int index) const;

private:

    std::vector<AnimationChannel*> _channels;
};

}
#endif