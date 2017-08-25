/*=================================================================|
|* File:				PenTool.h								  *|
|* Author:				Robert Jordan							  *|
|*																  *|
|=================================================================*/

#pragma once
#ifndef PEN_TOOL_H
#define PEN_TOOL_H

#include <string>
#include <AsciiArtist/Editing/Tool.h>

namespace AsciiArtist::Editing::Tools {
//=================================================================|
// CLASSES														   |
//=================================================================/

class PenTool : public Tool {
	
	//=========== MEMBERS ============
	#pragma region Members

	/* True if the secondary pixel is being drawn. */
	bool secondary;

	#pragma endregion
	//========= CONSTRUCTORS =========
	#pragma region Constructors
public:
	/* Constructs the tool. */
	PenTool(CanvasSPtr canvas);

	#pragma endregion
	//========== PROPERTIES ==========
	#pragma region Properties

	/* Gets the options used by the tool. */
	fixed_array<std::string> getUsedOptions() const final;

	#pragma endregion
	//=========== EDITING ============
	#pragma region Editing

	/* Finishes drawing with the tool. */
	void finalize() final;
	/* Cancels drawing with the tool. */
	void cancel() final;

	#pragma endregion
	//======== EVENT HANDLERS ========
	#pragma region Event Handlers

	void onMouseButton(MouseButtonEventArgs e) final;
	void onMouseMoved(MouseEventArgs e) final;
	void onPaint(PaintEventArgs e) final;

	#pragma endregion
};

DECLARE_SMART_PTRS(PenTool);

//=================================================================|
} /* End namespace */
#endif /* End include guard */
//=================================================================|
