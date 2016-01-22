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
        bool add(std::shared_ptr<T>)
        std::shared_ptr<T> get(size_t);
        bool remove(size_t);
        PointerStorage<T> mPointerStorage;
    };

    template <class T>
    bool Handler<T>::add(std::shared_ptr<T> obj)
    {
        return mPointerStorage.add(obj);
    }

    template <class T>
    std::shared_ptr<T> Handler<T>::get(size_t id)
    {
        return mPointerStorage.get(id);
    }

    template <class T>
    bool Handler<T>::remove(size_t id)
    {
        return mPointerStorage.remove(id);
    }
}

#endif
