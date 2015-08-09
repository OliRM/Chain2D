local Texture = {}
Texture.__index = Texture

function Texture.create()
    local texture = {}
    setmetatable(texture, Texture)

    texture.id = ch2d.texture.create()

    return texture
end

function Texture:remove()
    return ch2d.texture.remove(self.id)
end

function Texture:loadFromFile(filename)
    return ch2d.texture.loadFromFile(self.id, filename)
end

function Texture:setRepeated(repeated)
    return ch2d.texture.setRepeatead(self.id, repeated)
end

function Texture:setSmooth(smooth)
    return ch2d.texture.setSmooth(self.id, smooth)
end

function Texture:isRepeated()
    return ch2d.texture.isRepeated(self.id)
end

function Texture:isSmooth()
    return ch2d.texture.isSmooth(self.id)
end

return Texture
