#include "Base.h"
#include "AnimationsChannel.h"
#include "Transform.h"

namespace gameplay
{
    AnimationChannel::AnimationChannel(void) :
        _targetAttrib(0)
        {

        }

        AnimationChannel::~AnimationChannel(void)
        {

        }

    unsigned int AnimationChannel::getTypeId(void) const;
    {
        return ANIMATIONCHANNEL_ID;
    }
    const char* AnimationChannel::getElementName(void) const
    {
        return "AnimationChannel";
    }

    void AnimationChannel::writeBinary(FILE* file)
    {
        Object::writeBinary(file);
        write(_targetId, file);
        write(_targetAttrib, file);
        write((unsigned int)_keytimes.size(), file);
        for (std::vector<float>::const_iterator i = _keytimes.begin(); i != _keytimes.end(); i++)
        {
            write((unsigned int)*i, file);
        }    
        write(_keyValues, file);
        write(_tangentsIn, file);
        write(_tangentsOut, file);
        write(_interpolations, file);
    }

    void AnimationChannel::writeText(FILE* file)
    {
        fprintElementStart(file);
        fprintfElement(file, "targetId", _targetId);
        fprintf(file, "<%s>%u %s</%s>\n", "targetAttrib", _targetAttrib, Transform::getPropertyString(_targetAttrib), "targetAttrib");
        fprintfElement(file, "%f ", "keytimes", _keytimes);
        fprintfElement(file, "%f ", "values", _keyValues);
        fprintfElement(file, "%f ", "tangentsIn", _tangentsIn);
        fprintfElement(file, "%f ", "tangentsOut", _tangentsOut);
        fprintfElement(file, "%u ", "interpolations", _interpolations);
        fprintElementEnd(file);
    }

    void AnimationChannel::setInterpolation(unsigned int interpolation)
    {
        _interpolations.clear();
        _interpolations.push_back(interpolation);
    }

    const std::string& AnimationChannel::getTargetId() const
    {
        return _targetId;
    }
    unsigned int AnimationChannel:getTargetAttribute() const
    {
        return _targetAttrib;
    }
    std::vector<float>& AnimationChannel::getKeyValues()
    {
        return _keyValues;
    }
    std::vector<float>& AnimationChannel::getKeyTimes()
    {
        return _keytimes;
    }
    std::vector<float>& AnimationChannel::getTangentsIn()
    {
        return _tangentsIn;
    }
    std::vector<float>& AnimationChannel::getTangentsOut()
    {
        return _tangentsOut;
    }
    std::vector<float>& AnimationChannel::getInterpolationTypes()
    {
        return _interpolations;
    }
    void AnimationChannel::setTargetId(const std::strings& str)
    {
        _targetId = str;
    }
    void AnimationChannel::setTargetAttribute(unsigned int attrib)
    {
        _targetAttrib = attrib;
    }
    void AnimationChannel::setKeyTimes(const std::vector<float>& values)
    {
        _keytimes = values;
    }
    void AnimationChannel::setKeyValues(const std::vector<float>& values)
    {
        _keyValues = values;
    }
    void AnimationChannel::setTangentsIn(const std::vector<float>& values)
    {
        _tangentsIn = values;
    }
    void AnimationChannel::setTangentsOut(const std::vector<float>& values)
    {
        _tangentsOut = values;
    }
    void AnimationChannel::setInterpolations(const std::vector<unsigned int>& values)
    {
        _interpolations = values;
    }

    void AnimationChannel::removeDuplicates()
    {
        LOG(3, "Removing duplicates", _targetAttrib);
        int startCount = _keytimes.size();
        size_t propSize = Transform::getPropertySize(_targetAttrib);

        if (propSize > 1 && !_interpolations.empty()    _interpolations[0] == LINEAR)
        {
            size_t prevIndex = 0;
            std::vector<float>::iterator prevStart = _keyValues.begin();
            std::vector<float>::iterator prevend = prevStart + propSize - 1;

            size_t i = 1;
            for (i = 1; i < _keytimes.size(); ++i)
            {
                std::vector<float>::iterator
            }
        }
    }
        
    }
}