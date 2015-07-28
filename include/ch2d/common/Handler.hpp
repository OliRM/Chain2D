#ifndef CH2D_HANDLER_H
#define CH2D_HANDLER_H

// Standard
#include <memory>

// ch2d
#include <ch2d/common/PointerStorage.hpp>

namespace ch2d
{
    template <class T>
    class Handler
    {
    public:
        std::shared_ptr<T> get(unsigned int);
        bool remove(unsigned int);
        PointerStorage<T> mPointerStorage;
    };

    template <class T>
    std::shared_ptr<T> Handler<T>::get(unsigned int id)
    {
        return mPointerStorage.get(id);
    }

    template <class T>
    bool Handler<T>::remove(unsigned int id)
    {
        return mPointerStorage.remove(id);
    }
}

#endif
