# Email
Email program uses simple-mail for Qt to send an alert HTML email via smtp.gmail.com. The HTML content of the email, the username, password, the sender email and several recipient emails can be given to the program as command line arguments. To use Email, the simple-mail libraries have to be compiled first. Email then assumes that the folder structure is like that:

$PATH/Email
$PATH/simple-mail/build/src/libSimpleMailQt6
