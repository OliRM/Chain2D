# ch2d
A small, barebones 2D framework used to create games in Lua, built with C++ and SFML.

Currenty incomplete.

## Requirements

*  Cmake >= 2.8
*  Lua >= 5.2
*  SFML >= 2.0

## Notes

*  Uses Jeremy Ong's Lua bindings, Selene. (https://github.com/jeremyong/Selene)
*  Creating or loading an asset, i.e. sprite, texture, view etc, returns an unsigned integer used for referencing. The integer is used to uniquely reference an object of the specified type. Assignment operations, such as spriteA = spriteB will not copy the object, but rather the reference. Calling ch2d.sprite.remove(spriteA) will destroy the object that both spriteA and spriteB point to.

## Example
```Lua
-- game.lua

-- Create the sprite
sprite = ch2d.sprite.create()

-- Load the texture
texture = ch2d.texture.load("example.png")

-- Set the sprite's texture
ch2d.sprite.setTexture(sprite, texture)

-- Move the sprite
ch2d.sprite.setPosition(320, 240)

function ch2d.update(dt)
  -- Draw the sprite every frame
  ch2d.sprite.draw(sprite)
end

```

## Todo
*  Merge src/ch2d/Engine.cpp and src/ch2d/LuaInterface.cpp
*  Parse command line arguments
  * Currently "game/game.lua" is hardcoded to load.
*  Support configuration files
*  Update bindings
  *  sound bindings
  *  SFML shape bindings (circle, rectangle)
  *  window modification bindings
*  Lua native quadtree and collision detection
*  Create a set of Lua constants equivelent to the sf::Keyboard::Keys SFML enumeration
*  Potential overhaul to OpenGL for native shader support and general efficiecy

## Currently supported bindings

####ch2d.sprite

*  create
*  draw
*  remove
*  setPosition
*  setOrigin
*  setRotation
*  remove
*  setTexture
*  setTextureRect

####ch2d.texture

*  load
*  remove

####ch2d.keyboard

*  isDown

####ch2d.mouse

*  x
*  y
*  isDown

####ch2d.view

*  create
*  remove
*  setCenter

####ch2d.viewport

*  create
*  remove
