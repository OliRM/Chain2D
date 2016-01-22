shape = ch2d.shape.rectangle.create()
ch2d.shape.rectangle.setSize(shape, 30, 30)
ch2d.shape.setPosition(shape, 100, 100)

function ch2d.update(dt)
	ch2d.window.draw(shape)
end
