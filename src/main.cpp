#include <QCoreApplication>
#include "SimpleMail"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString txtHTML="";
    QString username="";
    QString pwd="";
    QString from="";
    QVector<QString> to;

    if(argc < 5) {
        qDebug() << "Not enough parameters!";
        return -1;
    }

    txtHTML = a.arguments().at(1);
    username = a.arguments().at(2);
    pwd = a.arguments().at(3);
    from = a.arguments().at(4);
    QString mails;
    for(int n=5;n<argc;n++) {
        if(a.arguments().at(n)!="") {
            to.push_back(a.arguments().at(n));
            mails += mails + to[n-5] + ",";
        }
    }
    qDebug() << txtHTML << " " << username << " " << pwd << " " << from << " " <<
        mails;
    SimpleMail::Sender smtp;
    smtp.setHost(QLatin1String("smtp.gmail.com"));
    smtp.setPort(465);
    smtp.setConnectionType(SimpleMail::Sender::SslConnection);
    smtp.setUser(username);
    smtp.setPassword(pwd);

    SimpleMail::MimeMessage message;
    message.setSender(SimpleMail::EmailAddress(from, "MuDAQ"));
    for(int n=0;n<to.size();n++) {
        message.addTo(SimpleMail::EmailAddress(to[n], "Recipient"));
    }

    message.setSubject(QLatin1String("Mudaq alert"));

    SimpleMail::MimeHtml html;
    html.setHtml(txtHTML);
    message.addPart(&html);
    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send email!" << smtp.lastError();
        return -2;
    }
    smtp.quit();
    return 0;
}
