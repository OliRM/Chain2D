# ch2d
A small, barebones 2D framework used to create games in Lua.

Currently unfinished.


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
  isDown

####ch2d.view

*  create
*  remove
*  setCenter

####ch2d.viewport

*  create
*  remove
