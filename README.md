# EngineBase Documentation

## About The Project

EngineBase is currently based on raylib: https://www.raylib.com, loose coupling does, however, allow us to easily change that.

EngineBase provides a range of functionalities designed to facilitate the management and manipulation of
graphical elements within an application. At its core, EngineBase allows for the addition of textures and colors,
enabling the customization and dynamic rendering of graphical assets. Developers can use the addTexture method to
incorporate new textures by specifying file paths and categorization indices, while the addHexColor method enables the
addition of colors through hexadecimal values.

In terms of scene management, EngineBase offers methods to set and retrieve the current scene, thus allowing for dynamic
scene transitions and state changes within the application. The startGUI method initiates the graphical user interface,
which is crucial for user interaction.

The project also includes functionalities to handle application state and visual feedback. The shouldAppClose method
provides a way to determine if the application is set to close, while toggleFPSCounter and getShowFPS methods manage the
visibility of the frames-per-second (FPS) counter, which is useful for performance monitoring.

Additionally, EngineBase supports object tracking features, enabling the camera or view to follow specific drawable
objects. The setObjectToFollow method allows developers to specify which object should be tracked, and the
getObjectToFollow method retrieves the currently followed object, facilitating dynamic camera movements and focused
views within the application.

Overall, EngineBase offers a comprehensive suite of tools for managing textures, scenes, application states, and object
tracking, providing a robust foundation for developing interactive and visually dynamic applications.

## DrawAbleObject

DrawAbleObject consists of multiple components:

- ConnectionManager
- DragAble
- SceneManager
- TextureManager
- Visibilty
- Button

And inherits from Object.

## Object

The `Object` class represents a rectangular object with properties for position and size. It provides methods for
manipulating and retrieving these properties and checking if a point is within the object's boundaries.

### Public Methods

- **`Object(int x, int y, int height, int width)`**

  Constructs an `Object` with the specified position (`x`, `y`) and dimensions (`height`, `width`).

- **`void setX(int x)`**

  Sets the x-coordinate of the object.

- **`void setY(int y)`**

  Sets the y-coordinate of the object.

- **`void setHeight(int height)`**

  Sets the height of the object.

- **`void setWidth(int width)`**

  Sets the width of the object.

- **`int getX() const`**

  Retrieves the x-coordinate of the object.

- **`int getY() const`**

  Retrieves the y-coordinate of the object.

- **`int getHeight() const`**

  Retrieves the height of the object.

- **`int getWidth() const`**

  Retrieves the width of the object.

- **`virtual bool isPointInside(int x, int y)`**

  Checks if a given point (`x`, `y`) is inside the object's boundaries.

### Protected Members

- **`int x`**

  The x-coordinate of the object's position.

- **`int y`**

  The y-coordinate of the object's position.

- **`int mHeight`**

  The height of the object.

- **`int mWidth`**

  The width of the object.

## ConnectionManager

Allows DrawAbleObjects to be connected, this includes hitbox and when drawing.

The `ConnectionManager` class manages connections of `DrawAbleObject` instances, allowing them to be connected,
disconnected, and retrieved as a sorted list.

### Public Methods

- **`ConnectionManager()`**

  Default constructor for the `ConnectionManager` class.

- **`void connectDrawAble(DrawAbleObject* drawAble)`**

  Connects a `DrawAbleObject` to the manager, adding it to the list of connected objects.

- **`void disconnectDrawAble(DrawAbleObject* drawAble)`**

  Disconnects a `DrawAbleObject` from the manager, removing it from the list of connected objects.

- **`std::list<DrawAbleObject*> getConnectedObjects()`**

  Retrieves a sorted list of all connected `DrawAbleObject` instances.

### Private Members

- **`void sortList()`**

  Sorts the list of connected `DrawAbleObject`.

- **`std::list<DrawAbleObject*> mConnectedObjects`**

  A list containing pointers to the connected `DrawAbleObject` instances.

## DragAble

Allows an object to be dragAble, this also drags connectedTextures. \
Currently only changes x,y coordinates of dragged objects.

### Public Methods

- **`DragAble()`**

  Default constructor for the `DragAble` class.

- **`void setDragable(bool isDragable)`**

  Sets the draggability state of the object.

- **`bool isDragable() const`**

  Checks if the object is currently draggable.

- **`bool isBeingDragged()`**

  Indicates whether the object is currently being dragged.

- **`void startDrag(DrawAbleObject* drawAble, int x, int y)`**

  Initiates the dragging process for the specified `DrawAbleObject`, starting at the given x and y coordinates.

- **`void updateDragPos(DrawAbleObject* drawAble, int x, int y)`**

  Updates the position of the specified `DrawAbleObject` during dragging to the new x and y coordinates.

- **`void cancelDrag(DrawAbleObject* drawAble)`**

  Cancels the dragging process for the specified `DrawAbleObject`.

- **`void stopDrag()`**

  Stops the dragging process.

### Private Members

- **`bool mIsDragable = false`**

  Indicates if the object is draggable.

- **`bool mIsBeingDragged = false`**

  Indicates if the object is currently being dragged.

- **`int oldX`**

  Stores the previous x-coordinate during dragging.

- **`int oldY`**

  Stores the previous y-coordinate during dragging.

- **`int mTransformX`**

  Represents the transformation in the x-direction during dragging.

- **`int mTransformY`**

  Represents the transformation in the y-direction during dragging.

## SceneManager

The `SceneManager` class manages the current scene in the application, providing methods to set and retrieve the active
scene.

### Public Methods

- **`SceneManager()`**

  Default constructor for the `SceneManager` class.

- **`void setScene(int scene)`**

  Sets the current scene to the specified scene index.

- **`int getScene()`**

  Retrieves the current scene index.

### Private Members

- **`int mScene`**

  Stores the index of the current scene.

## TextureManager Class

The `TextureManager` class is responsible for managing textures and animations for drawable objects. It provides methods
to control the texture indices, animation frames, and other related settings.

### Public Methods

- **`TextureManager()`**

  Default constructor for the `TextureManager` class.

- **`void advanceAnimation()`**

  Advances the animation by updating the current frame based on the specified frames per animation frame.

- **`void setDrawAble(DrawAbleObject* drawAble)`**

  Assigns a `DrawAbleObject` to the texture manager for texture management.

- **`int getZ() const`**

  Retrieves the z-index of the texture.

- **`void setZ(int z)`**

  Sets the z-index of the texture.

- **`void setTextureIndex(int textureIndex)`**

  Sets the primary texture index.

- **`void setTextureSecondIndex(int secondIndex)`**

  Sets the secondary texture index.

- **`int getTextureIndex() const`**

  Retrieves the primary texture index.

- **`int getSecondTextureIndex() const`**

  Retrieves the secondary texture index.

- **`int getAnimationEndIndex() const`**

  Retrieves the end index for the animation.

- **`void setAnimationEndIndex(int animationFinalIndex)`**

  Sets the end index for the animation.

- **`int getFramesPerAnimationFrame() const`**

  Retrieves the number of frames per animation frame.

- **`void setFramesPerAnimationFrame(int framesPerUpdate)`**

  Sets the number of frames per animation frame.

- **`int getCurrentFrames() const`**

  Retrieves the current frame count.

- **`void setCurrentFrames(int currentFrames)`**

  Sets the current frame count.

### Private Members

- **`int z = 0`**

  The z-index of the texture.

- **`int mTextureIndex = 0`**

  The primary texture index.

- **`int mTextureSecondIndex = 0`**

  The secondary texture index.

- **`int mAnimationFinalIndex = 0`**

  The end index for the animation.

- **`int mFramesPerAnimationFrame = 0`**

  The number of frames per animation frame.

- **`int mCurrentFrames = 0`**

  The current frame count.

- **`int mFramesShown = 0`**

  Tracks the number of frames shown.

- **`DrawAbleObject* mDrawAble`**

  Pointer to the drawable object associated with the texture manager.

## Visibility

The `Visibility` class manages the visibility state of an object. It provides methods to set and check whether the
object is visible.

### Public Methods

- **`Visibility()`**

  Default constructor for the `Visibility` class.

- **`void setVisible(bool visible)`**

  Sets the visibility state of the object. Pass `true` to make the object visible or `false` to hide it.

- **`bool isVisible()`**

  Checks whether the object is currently visible. Returns `true` if the object is visible; otherwise, returns `false`.

### Private Members

- **`bool mIsVisible = true`**

  A boolean flag indicating the visibility state of the object. By default, the object is visible.

## Button

The `Button` class provides functionalities for creating and managing button components with customizable behavior on
click events.

### Public Methods

- **`Button()`**

  Default constructor for the `Button` class.

- **`virtual ~Button()`**

  Virtual destructor for the `Button` class.

- **`void setDrawAbleObject(DrawAbleObject* drawAble)`**

  Assigns a `DrawAbleObject` to the button, which can be used for rendering or interaction purposes.

- **`virtual void onClick()`**

  A virtual method that defines the action performed when the button is clicked. This method can be overridden in
  derived classes to provide custom behavior.

- **`void setOnClick(std::function<void(DrawAbleObject*)> function)`**

  Sets a callback function to be executed when the button is clicked. The function receives a `DrawAbleObject*` as its
  argument.

### Private Members

- **`std::function<void(DrawAbleObject*)> mFunction`**

  A function object that stores the callback function to be executed on a button click.

- **`DrawAbleObject* mDrawAble`**

  A pointer to a `DrawAbleObject` associated with the button.
  The DrawAbleObject is passed into the function call.

## EngineBase

EngineBase is the name of the static class that acts\
as a gateway between the GUI thread, and application thread.

### Methods

- **`static void addTexture(const std::string& texturePath, int primaryIndex, int secondaryIndex)`**

  Adds a texture to the application using the specified texture file path and indices for categorization.

- **`static void addHexColor(unsigned int hexValue, int primaryIndex, int secondaryIndex)`**

  Adds a color to the application using a hexadecimal color value and indices for categorization.

- **`static void setScene(int scene)`**

  Sets the current scene to the specified scene index.

- **`static int getScene()`**

  Retrieves the current scene index.

- **`static void startGUI()`**

  Initiates the graphical user interface of the application.

- **`static bool shouldAppClose()`**

  Checks whether the application should close.

- **`static void toggleFPSCounter()`**

  Toggles the display of the frames-per-second (FPS) counter in the application.

- **`static bool getShowFPS()`**

  Returns whether the FPS counter is currently shown.

- **`static void setObjectToFollow(DrawAbleObject* drawAble)`**

  Sets the camera or view to follow a specified drawable object.

- **`static DrawAbleObject* getObjectToFollow()`**

  Retrieves the drawable object that the camera or view is currently following.


