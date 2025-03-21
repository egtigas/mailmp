Global variables

userCount -- number of users in user.txt (includes last new line (?))

main {
    user login {
		//Login_User loads the user.txt file
		//Load message file after successful login on User Page
		//Goes to User Page
        compose message {
			compose message {}
			compose annoncement {}
		}
        inbox{
			compose message {}
		}
        view sent messages{}
		view announcement {
			compose annoncement {}
		}
        modify personal contents {
			Modify_Personal_Contents(int user_index)
		}
        modify account security {
			Modify_Account_Security(int user_index)
		}
        modify personal connection {
			personal connection {}
		}
        browse users {
			Browse_Users(int user_index)
			compose message {}
		}
        logout {
			main {}
			//Message file will only be saved after logout
			Save_Message_File {}
		}
    }
	
    create new account {
		Create_Account()
	}
	
    request forgotten passwd {
		forgot_password()
	}
	
    admin {
		user module {
			view users {
				Browse_Users(int user_index)
			}
			refresh user account password {
				forgot_password()
			}
			delete user {
				Browse_Users(int user_index)
			}
			modify users {
				Browse_Users(int user_index)
				personal connection {}
			}
		}
		messages module {
			delete message {
				compose message {}
				compose annoncement {}
			}
			view messages {
				compose message {}
				compose annoncement {}
			}
			view by filter {
				compose message {}
				compose annoncement {}
			}
		}
		change password module {
		}
	}    
}