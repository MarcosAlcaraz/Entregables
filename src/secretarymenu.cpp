#include "secretarymenu.hpp"

using namespace std;

SecretaryMenu::SecretaryMenu() { }

//SecretaryMenu::SecretaryMenu(AgentList*) { }

void SecretaryMenu::mainMenu()
{
    int menu0;
    do
    {
        cout << "MENU PRINCIPAL";
        cout << "\n\t\t[\t\tAgentes\t\t]";
        cout << "\n1) Agregar Nuevo Agente.";
        cout << "\n2) Eliminar Agente Existente.";
        cout << "\n3) Mostrar Agentes Existentes.";
        cout << "\n4) Ordenar Lista de Agentes.";
        cout << "\n\n\t\t[\t\tClientes\t\t]";
        cout << "\n5) Añadir Cliente/Llamada a un Agente.";
        cout << "\n6) Eliminar Cliente/Llamada a un Agente.";
        cout << "\n7) Modificar Duración de Llamada de un CLiente/Llamada.";
        cout << "\n\n\t\t[\t\tGuardar/Cargar\t\t]";
        cout << "\n154) Guardar Lista de Agentes y Clientes Atendidos.";
        cout << "\n360) Cargar Lista de Agentes y Clientes Atendidos.";
        cout << "\n\n: ";

        cin >> menu0;

        switch (menu0)
        {
        case 1:
            addAgent();
            break;
        case 2:
            delAgent();
            break;
        case 3:
            showAgentList();
            break;
        case 4:
            sornAgentList();
            break;
        case 5:
            addClientToAgent();
            break;
        case 6:
            deleteClientToAgent();
            break;
        case 7:
            modAtDrtnToAgent();
            break;
        case 8:
            saveLists();
            break;
        case 9:
            loadLists();
            break;

        default:
            break;
        }
    } while (menu0 != 0);
}

void SecretaryMenu::addAgent()
{
    // Crear agente
    // Nombre del Agente
    Agent *nag = new Agent();
    DoubleNode *ndn = new DoubleNode();
    Name *N = new Name();
    Time *T = new Time();
    int o;
    string cadena;

    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Nombres: ";
    cin >> cadena;
    N->setFirstName(cadena);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Apellidos: ";
    cin >> cadena;
    system("clear");
    N->setLastName(cadena);
    nag->setName(*N);

    // Especialidad del Agente
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "\nCREAR AGENTE\n\n";
    cout << "Especialidad: ";
    cout << "\n1) Servidores.";
    cout << "\n2) De Escritorio.";
    cout << "\n3) Portatiles.";
    cout << "\n4) Linux.";
    cout << "\n5) Impresoras.";
    cout << "\n6) Redes.\n: ";
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
    }
    nag->setSpeciality(cadena);

    // Número de Extensión del Agente
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Numero de Extension [4 digitos]\n: ";
    cin >> cadena;
    nag->setExtensionNumber(cadena);

    // Numero de empleado del Agente
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Numero de empleado [9 digitos]\n: ";
    cin >> cadena;
    nag->setEmployeeNumber(cadena);

    // Hora de entrada
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Hora de entrada [HH:]\n: ";
    cin >> o;
    T->setHour(o);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Minuto de entrada [:MM:]\n: ";
    cin >> o;
    T->setMinute(o);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Segundo de entrada [:SS]\n: ";
    cin >> o;
    T->setSecond(o);
    nag->setStartTime(*T);

    // Hora de salida
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Hora de Salida [HH:]\n: ";
    cin >> o;
    T->setHour(o);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Minuto de Salida [:MM:]\n: ";
    cin >> o;
    T->setMinute(o);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Segundo de Salida [:SS]\n: ";
    cin >> o;
    T->setSecond(o);
    nag->setEndTime(*T);

    // Horas Extra
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Horas extras [0-4]\n: ";
    cin >> o;
    nag->setExtraHours(o);

    // Almacenar el agente en un nodo
    ndn->setData(*nag);

    // Insertar Nodo en aList
    aList.insertAgent(*ndn);
    system("clear");
    cout << "\nCREAR AGENTE\n\n";
    cout << "Agente añadido Exitosamente";
}

void SecretaryMenu::delAgent()
{
    DoubleNode* aux = aList.getFirstPos();
    string myString;
    char c;
    int x;

    system("cls");
    cout << "Menu Eliminar Agente" << endl << endl;
    cout << "1) Eliminar Agente" << endl;
    cout << "2) Eliminar todos los Agentes" << endl;
    cin >> x;
    if(x == 1)
    {
        cout << "N° de Empelado: ";
    cin >> myString;

    do
    {
        if(aux->getData().getEmployeeNumber() == myString)
        {
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString();
            cout << "Desea eliminar este Agente? (S/N): ";
            cin >> c;
            
            toupper(c);

            if(c == 'S')
            {
                aList.deleteNode(aux);
                cout << "Agente eliminado satisfactoriamente" << endl;
            }
            cout << "Retornando al menu principal" << endl;
            pause();
            return;
        }
        else
        {
            aux = aux->getNext();
            if(aux == nullptr)
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
        aList.deleteAll();
    }
}

void SecretaryMenu::showAgentList()
{
    DoubleNode* aux = aList.getFirstPos();
    system("cls");
    cout << "Menu Mostrar lista de agentes" << endl << endl;

    if(aux == nullptr)
    {
        cout << "Lista Vacia" << endl;
        cout << "Retornando al menu principal" << endl;
        pause();
        return;
    }
    do 
    {
        cout << aList.toString();
        aux = aux->getNext();
    } while(aux != nullptr);
    pause();
}

void SecretaryMenu::sornAgentList()
{
}

void SecretaryMenu::findAgent()
{
    DoubleNode* aux = aList.getFirstPos();
    string myString;

    system("cls");
    cout << "Menu Buscar Agente" << endl << endl;
    cout << "N° de Empelado: ";
    cin >> myString;

    do
    {
        if(aux->getData().getEmployeeNumber() == myString)
        {
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString();
            pause();
        }
        else
        {
            aux = aux->getNext();
            if(aux == nullptr)
            {
                cout << "El Agente no ha sido encontrado" << endl;
                cout << "Regresando al menu principal" << endl;
                pause();
            }
        }
    } while (aux != nullptr);   
}

void SecretaryMenu::modAgent()
{
    Name n;
    Time t;
    DoubleNode* aux = aList.getFirstPos();
    string myString;
    int x;

    system("cls");
    cout << "Menu Modificar Agente" << endl << endl;
    cout << "N° de Empelado: ";
    cin >> myString;

    do
    {
        if(aux->getData().getEmployeeNumber() == myString)
        {
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString() << endl << endl;
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
                    cout << "N°Extension: ";
                    cin >> myString;
                    aux->getData().setExtensionNumber(myString);
                }
                break;
            case 2:
                {
                    cout << "Especialidad: ";
                    cin >> myString;
                    aux->getData().setSpeciality(myString);
                }
                break;
            case 3:
                {
                    cout << "N°Empleado: ";
                    cin >> myString;
                    aux->getData().setEmployeeNumber(myString);
                }
                break;
            case 4:
                {
                    cout << "Horas Extra: ";
                    cin >> x;
                    aux->getData().setExtraHours(x);
                }
                break;
            case 5:
                {
                    cout << "Primer Nombre: ";
                    cin >> myString;
                    n.setFirstName(myString);
                    cout << "Segundo Nombre: ";
                    cin >> myString;
                    n.setSecondName(myString);
                    cout << "Apellido Materno: ";
                    cin >> myString;
                    n.setMothersLastName(myString);
                    cout << "Apellido Paterno: ";
                    cin >> myString;
                    n.setLastName(myString);
                    aux->getData().setName(n);
                }
                break;
            case 6:
                {
                    cout << "Hora: ";
                    cin >> x;
                    t.setHour(x);
                    cout << "Minuto: ";
                    cin >> x;
                    t.setMinute(x);
                    cout << "Segundo: ";
                    cin >> x;
                    t.setSecond(x);
                    aux->getData().setStartTime(t);
                }
                break;
            case 7:
                {
                    cout << "Hora: ";
                    cin >> x;
                    t.setHour(x);
                    cout << "Minuto: ";
                    cin >> x;
                    t.setMinute(x);
                    cout << "Segundo: ";
                    cin >> x;
                    t.setSecond(x);
                    aux->getData().setEndTime(t);
                }
                break;
            
            default:
                break;
            }
            cout << "Dato modificado correctamente" << endl << endl;
            cout << aux->getData().toString();
            pause();
        }
        else
        {
            aux = aux->getNext();
            if(aux == nullptr)
            {
                cout << "El Agente no ha sido encontrado" << endl;
                cout << "Regresando al menu principal" << endl;
                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::addClientToAgent()
{
    SimplyNode *node = new SimplyNode();
    DoubleNode *aux = aList.getFirstPos();
    Agent *modAgent = new Agent();
    Client *call = new Client();
    Time *t = new Time();
    string cadena;
    int x;

    // Hora de atención
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nHora de atencion [HH:]\n: ";
    cin >> x;
    t->setHour(x);
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nMinuto de atencion [:MM:]\n: ";
    cin >> x;
    t->setMinute(x);
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nSegundo de atencion [:SS]\n: ";
    cin >> x;
    t->setSecond(x);

    call->setTimeAtention(*t);

    // Duración de la llamada
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nHora de la Duracion de la llamada [HH:]\n: ";
    cin >> x;
    t->setHour(x);
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nMinuto de la duracion de la llamada [:MM:]\n: ";
    cin >> x;
    t->setMinute(x);
    system("clear");
    cout << "AÑADIR CLIENTE A UN AGENTE";
    cout << "\nSegundo de la duracion de la llamada [:SS]\n: ";
    cin >> x;
    t->setSecond(x);

    call->setAtentionDuration(*t);
    node->setData(*call);

    // Busqueda de cliente por número de empleado
    system("clear");
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

void SecretaryMenu::deleteClientToAgent()
{
    int x;
    SimplyNode *s;
    DoubleNode *a = aList.getFirstPos();

    system("clear");
    cout << "ELIMINAR LLAMADA\n";
    cout << "\n1) Eliminar una Llamada.";
    cout << "\n2) Eliminar Todas las Llamadas.\n: ";

    if (x == 1)
    {
        system("clear");
        cout << "ELIMINAR LLAMADA\n";
        cout << "\nSelecciona un Agente.\n\n";
        aList.toString();
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            a = a->getNext();
        }

        system("clear");
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
        system("clear");
        cout << "ELIMINAR TODAS LAS LLAMADAS\n";
        cout << "\nSelecciona un Agente.\n\n";
        aList.toString();
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            a = a->getNext();
        }
        a->getData().getClientList().deleteAll();
    }
}

void SecretaryMenu::modAtDrtnToAgent() // E6
{
    Time *t = new Time();
    DoubleNode *a = aList.getFirstPos();
    SimplyNode *s;
    int x;

    system("clear");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    cout << "\nSelecciona un Agente.\n\n";
    aList.toString();
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        a = a->getNext();
    }

    system("clear");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    cout << "\nSelecciona una Llamada.\n\n";
    s = a->getData().getClientList().getFirstPos();
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        s = s->getNext();
    }

    system("clear");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    cout << "NUEVA HORA PARA EL CLIENTE SELECCIONADO";
    cout << "\nHH: ";
    cin >> x;
    t->setHour(x);
    cout << "\nMM: ";
    cin >> x;
    t->setMinute(x);
    cout << "\nSS: ";
    cin >> x;
    t->setSecond(x);

    s->getData().setTimeAtention(*t);
}

void SecretaryMenu::saveLists()
{
}

void SecretaryMenu::loadLists()
{
}

void SecretaryMenu::pause()
{
    cout <<"Enter para continuar...";
    cin.get();
}
