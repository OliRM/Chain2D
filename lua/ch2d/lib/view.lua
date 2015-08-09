local View = {}
View.__index = View

function View.create()
    local view = {}
    setmetatable(view, View)

    view.id = ch2d.view.create()

    return view
end

function View:remove()
    return ch2d.view.remove(self.id)
end

function View:setCenter(_x, _y)
    return ch2d.view.setCenter(self.id, _x, _y)
end

function View:setSize(_width, _height)
    return ch2d.view.setSize(self.id, _width, _height)
end

function View:setRotation(_degrees)
    return ch2d.view.setRotation(self.id, _degrees)
end

function View:setViewport(_top, _left, _width, _height)
    return ch2d.view.setViewport(self.id, _top, _left, _width, _height)
end

function View:getCenter()
    return ch2d.view.getCenter(self.id)
end

function View:getSize()
    return ch2d.view.getSize(self.id)
end

function View:getRotation()
    return ch2d.view.getRotation(self.id)
end

function View:getViewport()
    return ch2d.view.getViewport(self.id)
end

return View
