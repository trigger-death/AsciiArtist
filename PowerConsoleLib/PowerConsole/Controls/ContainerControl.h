/*=================================================================|
|* File:				ContainerControl.h						  *|
|* Author:				Robert Jordan							  *|
|*																  *|
|=================================================================*/

#pragma once
#ifndef CONTAINER_CONTROL_H
#define CONTAINER_CONTROL_H

#include <PowerConsole/Controls/Control.h>
#include <PowerConsole/Controls/IChildContainer.h>
#include <PowerConsole/Controls/Events/EventArgs.h>

namespace PowerConsole::Controls {
//=================================================================|
// CLASSES														   |
//=================================================================/

/* The base class for containing controls. */
class ContainerControl : public Control, public IChildContainer {

	//=========== MEMBERS ============
	#pragma region Members
private:
	/* The collection of child controls. */
	ControlCollection collection;

	#pragma endregion
	//========= CONSTRUCTORS =========
	#pragma region Constructors
public:
	/* Constructs the base control container. */
	ContainerControl();
	/* Initializes the control. */
	void onInitialize(ControlSPtr sender, EventArgs& e);

	#pragma endregion
	//========== PROPERTIES ==========
	#pragma region Properties

	/* Returns true if the control or any of its children has the specified name. */
	bool containsName(const std::string& name) const override;

	/* Gets the collection of all the children contained by this control. */
	ControlCollection& children();
	/* Gets the collection of all the children contained by this control. */
	const ControlCollection& children() const;

	#pragma endregion
	//=========== UPDATING ===========
	#pragma region Updating

	/* Updates the layout of the control after changes have been made to the control's layout properties. */
	//virtual void updateLayout(bool sizeChanged, bool marginChanged, bool alignmentChanged, bool positionChanged, bool visibleAreaChanged);
	/* Sets the layout of the specified child. */
	virtual void updateChildLayout(ControlSPtr control);

	/* Iterates through all controls contained within this one. */
	void forEach(std::function<void(ControlSPtr control)> func) override;
	/* Draws the control to the graphics object. */
	void repaint(PcDraw::GraphicsSPtr g) override;

	#pragma endregion
	//============ EVENTS ============
	#pragma region Events

	/* Called when a child has been added to the collection. */
	Event<ChildModifiedEventArgs>& eventChildAdded() override;
	/* Called when a child has been removed from the collection. */
	Event<ChildModifiedEventArgs>& eventChildRemoved() override;

	#pragma endregion
	//======== EVENT HANDLERS ========
	#pragma region Event Handlers
private:
	void onLayoutChanged(ControlSPtr sender, LayoutChangedEventArgs& e);
	void onChildAdded(ControlSPtr sender, ChildModifiedEventArgs& e);

	#pragma endregion
};

//=================================================================|
} /* End namespace */
#endif /* End include guard */
//=================================================================|
