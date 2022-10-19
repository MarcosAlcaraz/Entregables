#include "secretarymenu.hpp"

using namespace std;

SecretaryMenu::SecretaryMenu() {}

// SecretaryMenu::SecretaryMenu(AgentList*) { }

void SecretaryMenu::mainMenu()
{
    AgentList *aList = new AgentList();
    int menu0;
    do
    {
        cout << "MENU PRINCIPAL";
        cout << "\n[          Agentes         ]";
        cout << "\n\t1) Agregar";
        cout << "\n\t2) Eliminar";
        cout << "\n\t3) Mostrar";
        cout << "\n\t4) Ordenar";
        cout << "\n\n[         Clientes         ]";
        cout << "\n\t5) Agregar";
        cout << "\n\t6) Eliminar";
        cout << "\n\t7) Modificar";
        cout << "\n\n[       Guardar/Cargar     ]";
        cout << "\n\t8) Guardar";
        cout << "\n\t9) Cargar.";
        cout << "\n\n: ";

        cin >> menu0;

        switch (menu0)
        {
        case 1:
            addAgent(aList);
            break;
        case 2:
            delAgent(aList);
            break;
        case 3:
            showAgentList(aList);
            break;
        case 4:
            sornAgentList(aList);
            break;
        case 5:
            addClientToAgent(aList);
            break;
        case 6:
            deleteClientToAgent(aList);
            break;
        case 7:
            modAtDrtnToAgent(aList);
            break;
        case 8:
            saveLists(aList);
            break;
        case 9:
            loadLists(aList);
            break;
        default:
            break;
        }
    } while (menu0 != 0);
}

void SecretaryMenu::addAgent(AgentList *aList)
{
    // AGREGAR NUEVO AGENTE
    Agent *nag = new Agent();           // nag = nEW agENT
    DoubleNode *ndn = new DoubleNode(); // Agent Node
    Name *N = new Name();
    Time *T = new Time();
    string cadena;
    int o;

    // Nombre y Apellido
    system("cls");
    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Nombre(s): ";
    cin >> cadena;
    N->setName(cadena);
    system("cls");

    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Apellidos: ";
    cin >> cadena;
    N->setLastName(cadena);
    nag->setName(*N);

    do
    {
        // Especialidad del Agente
        system("cls");
        cout << "\n\tAGREGAR NUEVO AGENTE\n\n";
        cout << "Especialidad: ";
        cout << "\n\t1) Servidores.";
        cout << "\n\t2) De Escritorio.";
        cout << "\n\t3) Portatiles.";
        cout << "\n\t4) Linux.";
        cout << "\n\t5) Impresoras.";
        cout << "\n\t6) Redes.\n: ";
        cin >> o;
        switch (o)
        {
        case 1:
            cadena = "Servidores";
            break;
        case 2:
            cadena = "De Escritorio";
            break;
        case 3:
            cadena = "Portatiles";
            break;
        case 4:
            cadena = "Linux";
            break;
        case 5:
            cadena = "Impresoras";
            break;
        case 6:
            cadena = "Redes";
            break;
        default:
        {
            system("cls");
            cout << "Escoja una opcion del menu...";
            pause();
        }
        }
    } while (o < 7 && o > 0);

    nag->setSpeciality(cadena);

    // Número de Extensión del Agente
    system("cls");
    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Numero de Extension [4 digitos]\n: ";
    cin >> cadena;
    cadena = to_string(o);
    nag->setExtensionNumber(cadena);

    // Numero de empleado del Agente
    system("cls");
    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Numero de empleado [9 digitos]\n: ";
    cin >> o;
    cadena = to_string(o);
    nag->setEmployeeNumber(cadena);

    do
    {
        // Hora de entrada
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Hora de entrada [HH:]\n: ";
        cin >> o;
    } while (o < 25 && o > 0);
    T->setHour(o);

    do
    {
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Minuto de entrada [:MM:]\n: ";
        cin >> o;
    } while (o < 60 && o > 0);
    T->setMinute(o);

    do
    {
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Segundo de entrada [:SS]\n: ";
        cin >> o;
    } while (o < 60 && o > 0);
    T->setSecond(o);

    nag->setStartTime(*T);

    do
    {
        // Hora de salida
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Hora de Salida [HH:]\n: ";
        cin >> o;
    } while (o < 25 && o > 0);
    T->setHour(o);

    do
    {
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Minuto de Salida [:MM:]\n: ";
        cin >> o;
    } while (o < 60 && o > 0);
    T->setMinute(o);

    do
    {
        system("cls");
        cout << "\nAGREGAR NUEVO AGENTE\n\n";
        cout << "Segundo de Salida [:SS]\n: ";
        cin >> o;
    } while (o < 60 && o > 0);
    T->setSecond(o);

    nag->setEndTime(*T);

    // Horas Extra
    system("cls");
    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Horas extras [0-4]\n: ";
    cin >> o;
    nag->setExtraHours(o);

    // Almacenar el agente en un nodo
    ndn->setData(*nag);

    // Insertar Nodo en aList
    aList->insertAgent(*ndn);

    system("cls");
    cout << "\nAGREGAR NUEVO AGENTE\n\n";
    cout << "Agente añadido Exitosamente";
    pause();
}

void SecretaryMenu::delAgent(AgentList *aList)
{
    DoubleNode *aux = aList->getFirstPos();
    string myString;
    char c;
    int x;

    system("cls");
    cout << "Menu Eliminar Agente" << endl
         << endl;
    cout << "1) Eliminar un Agente" << endl;
    cout << "2) Eliminar todos los Agentes" << endl;
    cin >> x;
    if (x == 1)
    {
        cout << "N° de Empelado: ";
        cin >> myString;
        do
        {
            if (aux->getData().getEmployeeNumber() == myString)
            {
                cout << "Agente encontrado" << endl;
                cout << aux->getData().toString();
                cout << "Desea eliminar este Agente? (S/N): ";
                cin >> c;

                toupper(c);

                if (c == 'S')
                {
                    aList->deleteNode(aux);
                    cout << "Agente eliminado satisfactoriamente" << endl;
                }
                cout << "Retornando al menu principal" << endl;
                pause();
                return;
            }
            else
            {
                aux = aux->getNext();
                if (aux == nullptr)
                {
                    cout << "El Agente no ha sido encontrado" << endl;
                    cout << "Regresando al menu principal" << endl;
                    pause();
                }
            }
        } while (aux != nullptr);
    }
    else
    {
        aList->deleteAll();
    }
}

void SecretaryMenu::showAgentList(AgentList *aList)
{
    DoubleNode *aux = aList->getFirstPos();
    system("cls");
    cout << "Menu Mostrar lista de agentes" << endl
         << endl;

    if (aux == nullptr)
    {
        cout << "Lista Vacia" << endl;
        cout << "Retornando al menu principal" << endl;
        pause();
        return;
    }
    do
    {
        cout << aList->toString();
        aux = aux->getNext();
    } while (aux != nullptr);
    pause();
}

void SecretaryMenu::sornAgentList(AgentList *aList)
{
    cout << "COMING SOON";
    pause();
}

void SecretaryMenu::findAgent(AgentList *aList)
{
    DoubleNode *aux = aList->getFirstPos();
    string myString;
    int x;

    system("cls");
    cout << "Menu Buscar Agente" << endl
         << endl;
    cout << "N° de Empelado: ";
    cin >> x;
    myString = to_string(x);

    do
    {
        if (aux->getData().getEmployeeNumber() == myString)
        {
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString();
            pause();
        }
        else
        {
            aux = aux->getNext();
            if (aux == nullptr)
            {
                cout << "El Agente no ha sido encontrado" << endl;
                cout << "Regresando al menu principal" << endl;
                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::modAgent(AgentList *aList)
{
    Name n;
    Time t;
    DoubleNode *aux = aList->getFirstPos();
    string myString;
    int x;

    system("cls");
    cout << "Menu Modificar Agente" << endl
         << endl;
    cout << "N° de Empelado: ";
    cin >> x;
    myString = to_string(x);

    do
    {
        if (aux->getData().getEmployeeNumber() == myString)
        {
            system("cls");
            cout << "Menu Modificar Agente" << endl
                 << endl;
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString() << endl
                 << endl;
            cout << "Escoja el dato a modificar: ";
            cout << "1) N°Extension" << endl;
            cout << "2) Especialidad" << endl;
            cout << "3) N°Empleado" << endl;
            cout << "4) Horas Extra" << endl;
            cout << "5) Nombre" << endl;
            cout << "6) Hora de Entrada" << endl;
            cout << "7) Hora de salida" << endl;
            cout << ": ";
            cin >> x;

            system("cls");
            cout << "Menu Modificar Agente" << endl;
            cout << "Escriba el nuevo dato: " << endl;

            switch (x)
            {
            case 1:
            {
                cout << "\nN°Extension: ";
                cin >> myString;
                aux->getData().setExtensionNumber(myString);
            }
            break;
            case 2:
            {
                cout << "\nEspecialidad: ";
                cin >> myString;
                aux->getData().setSpeciality(myString);
            }
            break;
            case 3:
            {
                cout << "\nN°Empleado: ";
                cin >> myString;
                aux->getData().setEmployeeNumber(myString);
            }
            break;
            case 4:
            {
                cout << "\nHoras Extra: ";
                cin >> x;
                aux->getData().setExtraHours(x);
            }
            break;
            case 5:
            {
                cout << "\nNombre(s): ";
                cin >> myString;
                n.setName(myString);
                cout << "\nApellidos: ";
                cin >> myString;
                n.setLastName(myString);
                aux->getData().setName(n);
            }
            break;
            case 6:
            {
                do
                {
                    cout << "\nHora: ";
                    cin >> x;
                } while (x < 25 && x > 0);
                t.setHour(x);

                do
                {
                    cout << "\nMinuto: ";
                    cin >> x;
                } while (x < 60 && x > 0);
                t.setMinute(x);

                do
                {
                    cout << "\nSegundo: ";
                    cin >> x;
                } while (x < 60 && x > 0);
                t.setSecond(x);
                aux->getData().setStartTime(t);
            }
            break;
            case 7:
            {
                do
                {
                    cout << "\nHora: ";
                    cin >> x;
                } while (x < 25 && x > 0);
                t.setHour(x);

                do
                {
                    cout << "\nMinuto: ";
                    cin >> x;
                } while (x < 60 && x > 0);
                t.setMinute(x);

                do
                {
                    cout << "\nSegundo: ";
                    cin >> x;
                } while (x < 60 && x > 0);
                t.setSecond(x);
                aux->getData().setEndTime(t);
            }
            break;

            default:
                break;
            }
            cout << "\n\nDato modificado correctamente" << endl
                 << endl;
            cout << aux->getData().toString();
            pause();
        }
        else
        {
            aux = aux->getNext();
            if (aux == nullptr)
            {
                cout << "\nEl Agente no ha sido encontrado" << endl;
                cout << "\nRegresando al menu principal" << endl;
                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::addClientToAgent(AgentList *aList)
{
    SimplyNode *node = new SimplyNode();
    DoubleNode *aux = aList->getFirstPos();
    Agent *modAgent = new Agent();
    Client *call = new Client();
    Time *t = new Time();
    string cadena;
    int x;

    // Hora de atención
    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nHora de atencion [HH:]\n: ";
        cin >> x;
    } while (x < 25 && x > 0);
    t->setHour(x);

    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nMinuto de atencion [:MM:]\n: ";
        cin >> x;
    } while (x < 60 && x > 0);
    t->setMinute(x);

    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nSegundo de atencion [:SS]\n: ";
        cin >> x;
    } while (x < 60 && x > 0);
    t->setSecond(x);

    call->setTimeAtention(*t);

    // Duración de la llamada
    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nHora de la Duracion de la llamada [HH:]\n: ";
        cin >> x;

    } while (x < 25 && x > 0);
    t->setHour(x);

    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nMinuto de la duracion de la llamada [:MM:]\n: ";
        cin >> x;

    } while (x < 60 && x > 0);
    t->setMinute(x);

    do
    {
        system("cls");
        cout << "AÑADIR CLIENTE A UN AGENTE";
        cout << "\nSegundo de la duracion de la llamada [:SS]\n: ";
        cin >> x;
    } while (x < 60 && x > 0);
    t->setSecond(x);

    call->setAtentionDuration(*t);
    node->setData(*call);

    // Busqueda de cliente por número de empleado
    system("cls");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nNumero de empleado a quien se le añadira la llamada [9 digitos]\n: ";
    cin >> cadena;

    do
    {
        if (aux->getData().getEmployeeNumber() == cadena)
        {
            modAgent = &aux->getData();
            modAgent->getClientList().insertOrdered(*node);
        }
        else
        {
            aux = aux->getNext();
        }
    } while (aux != nullptr);

    // FIN DE Busqueda de cliente por número de empleado
}

void SecretaryMenu::deleteClientToAgent(AgentList *aList)
{
    int x;
    SimplyNode *s;
    DoubleNode *a = aList->getFirstPos();

    system("cls");
    cout << "ELIMINAR LLAMADA\n";
    cout << "\n1) Eliminar una Llamada.";
    cout << "\n2) Eliminar Todas las Llamadas.\n: ";

    if (x == 1)
    {
        system("cls");
        cout << "ELIMINAR LLAMADA\n";
        cout << "\nSelecciona un Agente.\n\n";
        aList->toString();
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            a = a->getNext();
        }

        system("cls");
        cout << "ELIMINAR LLAMADA\n";
        cout << "\nSelecciona una Llamada.\n\n";
        s = a->getData().getClientList().getFirstPos();
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            s = s->getNext();
        }

        delete s;
    }
    else
    {
        system("cls");
        cout << "ELIMINAR TODAS LAS LLAMADAS\n";
        cout << "\nSelecciona un Agente.\n\n";
        aList->toString();
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            a = a->getNext();
        }
        a->getData().getClientList().deleteAll();
    }
}

void SecretaryMenu::modAtDrtnToAgent(AgentList *aList) // E6
{
    Time *t = new Time();
    DoubleNode *a = aList->getFirstPos();
    SimplyNode *s;
    int x;

    system("cls");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    if(aList->getFirstPos() == nullptr)
    {
        cout <<"Lista Vacia\nRegresando al menu principal\n\n";
        pause();
        return;
    }
    cout << "\nSelecciona un Agente.\n\n";
    aList->toString();
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        a = a->getNext();
    }

    system("cls");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    if(a->getData().getClientList().getFirstPos() == nullptr)
    {
        cout <<"Lista Vacia\nRegresando al menu principal\n\n";
        pause();
        return;
    }
    cout << "\nSelecciona una Llamada.\n\n";
    s = a->getData().getClientList().getFirstPos();
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        s = s->getNext();
    }

    do
    {
        system("cls");
        cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
        cout << "NUEVA HORA PARA EL CLIENTE SELECCIONADO";
        cout << "\nHH: ";
        cin >> x;
    } while (x < 25 && x > 0);
    t->setHour(x);

    do
    {
        system("cls");
        cout << "\nMM: ";
        cin >> x;
    } while (x < 60 && x > 0);
    t->setMinute(x);

    do
    {
        system("cls");
        cout << "\nSS: ";
        cin >> x;
    } while (x < 60 && x > 0);
    t->setSecond(x);
    s->getData().setTimeAtention(*t);
}

void SecretaryMenu::saveLists(AgentList *aList)
{
}

void SecretaryMenu::loadLists(AgentList *aList)
{
}

void SecretaryMenu::pause()
{
    cout << "Enter para continuar...";
    cin.ignore();
}
