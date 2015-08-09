local Sprite = {}
Sprite.__index = Sprite

function Sprite.create()
	local sprite = {}
	setmetatable(sprite, Sprite)

	sprite.id = ch2d.sprite.create()

	return sprite
end

function Sprite:remove()
	return ch2d.sprite.remove(self.id)
end

function Sprite:draw()
	return ch2d.sprite.draw(self.id)
end

function Sprite:remove()
	return ch2d.sprite.remove(self.id)
end

function Sprite:setPosition(_x, _y)
	return ch2d.sprite.setPosition(self.id, _x, _y)
end

function Sprite:setOrigin(_x, _y)
	return ch2d.sprite.setOrigin(self.id, _x, _y)
end

function Sprite:setRotation(_degrees)
	return ch2d.sprite.setRotation(self.id, _degrees)
end

function Sprite:setScale(_x, _y)
	return ch2d.sprite.setScale(self.id, _x, _y)
end

function Sprite:setTexture(_textureId)
	return ch2d.sprite.setTexture(self.id, _textureId)
end

function Sprite:setTextureRect(_top, _left, _width, _height)
	return ch2d.sprite.setTextureRect(self.id, _top, _left, _width, _height)
end

function Sprite:getPosition()
	return ch2d.sprite.getPosition(self.id)
end

function Sprite:getOrigin()
	return ch2d.sprite.getOrigin(self.id)
end

function Sprite:getRotation()
	return ch2d.sprite.getRotation(self.id)
end

function Sprite:getScale()
	return ch2d.sprite.getScale(self.id)
end

return Sprite
