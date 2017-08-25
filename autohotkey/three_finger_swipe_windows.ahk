swipeDirection := ""

^!Tab::
	swipeDirection := "L"
return

^!+Tab::
	swipeDirection := "R"
return

$Enter::
	if (not swipeDirection) {
		SendInput {Enter}
	} else if (swipeDirection = "L") {
		MsgBox Swipe Left
		SendInput ^#{Left}
	} else if (swipeDirection = "R") {
		MsgBox Swipe 
		SendInput ^#{Right}
	}
	swipeDirection := ""
return