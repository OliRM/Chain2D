local Class = require "game.lib.class"
local Sprite = require "lua.ch2d.lib.sprite"
local Texture = require "lua.ch2d.lib.texture"
local RigidBody = require "game.lib.rigidbody"

local Entity = Class:create()

function Entity:new()
    self.sprite = Sprite.create()
    self.spritesheet = Texture.create()

    self.static = false
    self.collidable = false

    self.rigidBody = RigidBody(self)
    self.rigidBody.width = 0
    self.rigidBody.height = 0

    self.dimensions = {}
    self.dimensions.width = 0
    self.dimensions.height = 0

    self.origin = {}
    self.origin.x = 0
    self.origin.y = 0

    self.position = {}
    self.position.x = 0
    self.position.y = 0

    self.velocity = {}
    self.velocity.x = 0
    self.velocity.y = 0

    self.acceleration = {}
    self.acceleration.x = 0
    self.acceleration.y = 0
end

function Entity:update()
    --
end

function Entity:draw()
    self.sprite:draw()
end

function Entity:left()
    return self.position.x - self.origin.x
end

function Entity:top()
    return self.position.y - self.origin.y
end

function Entity:width()
    return self.dimensions.width
end

function Entity:height()
    return self.dimensions.height
end

function Entity:setDimensions(_x, _y)
    self.dimensions.x = _x
    self.dimensions.y = _x
end

function Entity:setOrigin(_x, _y)
    self.origin.x = _x
    self.origin.y = _x

    self.sprite:setOrigin(_x, _y)
end

function Entity:setPosition(_x, _y)
    self.position.x = _x
    self.position.y = _y

    self.sprite:setPosition(_x, _y)
end
function Entity:setVelocity(_x, _y)
    self.velocity.x = _x
    self.velocity.y = _y
end

return Entity
