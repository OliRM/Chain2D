# Chain 2D
A small, basic 2D engine used to create games in Lua, built with C++ and SFML.

## Requirements

*  Lua >= 5.2
*  SFML >= 2.0
*  A fully C++11 compliant compiler

## Installing

``` bash
cd ch2d
cmake .
make
```

## Example

``` Lua
-- game.lua

-- Create a sprite
sprite = ch2d.sprite.create()

-- Load a texture
texture = ch2d.texture.load("example.png")

-- Set the sprite's texture
ch2d.sprite.setTexture(sprite, texture)

-- Set the sprite's origin
ch2d.sprite.setOrigin(sprite, 16, 16)

function ch2d.update(dt)
  -- Move the sprite to the the mouse's current location on the screen
  ch2d.sprite.setPosition(sprite, ch2d.mouse.x(), ch2d.mouse.y())
  
  -- Draw the sprite
  ch2d.sprite.draw(sprite)
end
```

## Using classes

Instead of raw bindings, basic classes can be found in lua/ch2d/lib that allow for object control using methods, rather than interfacing directly with the engine with raw bindings.

There are three classes present in this directory.

* sprite.lua
* texture.lua
* view.lua

All methods take the form of the equivelent raw binding, but without requiring the objects id.

###### Example
``` Lua
-- Sprite class
Sprite = require "lua.ch2d.lib.sprite"

-- Texture class
Texture = require "lua.ch2d.lib.texture"

-- Create a sprite
sprite = Sprite.create()

-- Create a texture
texture = Texture.create()

-- Load an image frome file into the texture
texture:loadFromFile("example.png")

-- Set the sprite's texture
sprite:setTexture(texture.id)

function ch2d.update(dt)
    -- Draw the sprite
    sprite:draw()
end
```
## Raw Bindings

###### System bindings

``` Lua
void ch2d.system.quit(void)
```

----

###### Window bindings

``` Lua
bool ch2d.window.setView(unsigned int)
```

----

###### Sprite bindings

``` Lua
unsigned int   ch2d.sprite.create(void)
bool           ch2d.sprite.remove(unsigned int)
bool           ch2d.sprite.draw(unsigned int)
bool           ch2d.sprite.setPosition(unsigned int, double, double)
bool           ch2d.sprite.setOrigin(unsigned int, double, double)
bool           ch2d.sprite.setRotation(unsigned int, double)
bool           ch2d.sprite.setScale(unsigned int, double, double)
bool           ch2d.sprite.setTexture(unsigned int, unsigned int)
bool           ch2d.sprite.setTextureRect(unsigned int, double, double, double, double)
double, double ch2d.sprite.getPosition(unsigned int)
double, double ch2d.sprite.getOrigin(unsigned int)
double         ch2d.sprite.getRotation(unsigned int)
double, double ch2d.sprite.getScale(unsigned int)
```

----

###### Texture bindings

``` Lua
unsigned int ch2d.texture.create()
bool         ch2d.texture.loadFromFile(string)
bool         ch2d.texture.setRepeated(bool)
bool         ch2d.texture.setSmooth(bool)
bool         ch2d.texture.isRepeated()
bool         ch2d.texture.isSmooth()
bool         ch2d.texture.remove(unsigned int)
```

----

###### Keyboard bindings

``` Lua
bool ch2d.keyboard.isDown(unsigned int)
```

----

###### Mouse bindings

``` Lua
double ch2d.mouse.x(void)
double ch2d.mouse.y(void)
bool   ch2d.mouse.isDown(unsigned int)
```

----

###### View bindings

``` Lua
unsigned int                   ch2d.view.create()
bool                           ch2d.view.remove(unsigned int)
bool                           ch2d.view.setCenter(unsigned int, double, double)
bool                           ch2d.view.setSize(unsigned int, double, double)
bool                           ch2d.view.setRotation(unsigned int, double)
bool                           ch2d.view.setViewport(unsigned int, double, double, double, double)
double, double                 ch2d.view.getCenter(unsigned int)
double, double                 ch2d.view.getSize(unsigned int)
double                         ch2d.view.getRotation(unsigned int)
double, double, double, double ch2d.view.getViewport(unsigned int)
```
