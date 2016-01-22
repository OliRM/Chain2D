local Class = {}
Class.__index = Class

function Class:create()
    local class = {}
    setmetatable(class, self)

    for key, value in pairs(self) do
        if key:find("^__") then
            class[key] = value
        end
    end

    class.parent = self

    class.__index = class

    return class
end

function Class:__call(...)
    local class = {}
    setmetatable(class, self)

    if class.parent.new then
        class.parent.new(class)
    end

    if class.new then
        class:new(...)
    end

    return class
end

return Class
