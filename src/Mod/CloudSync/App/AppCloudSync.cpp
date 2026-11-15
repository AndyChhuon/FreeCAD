// SPDX-License-Identifier: LGPL-2.1-or-later

/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME <Your e-mail address>                    *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include <App/Application.h>
#include <App/Document.h>

#include <Python.h>


#include <Base/Console.h>
#include <Base/Interpreter.h>
#include <Base/PyObjectBase.h>

#include <CXX/Extensions.hxx>
#include <CXX/Objects.hxx>
namespace sp = std::placeholders;


namespace CloudSync
{
class Module: public Py::ExtensionModule<Module>
{
public:
    Module()
        : Py::ExtensionModule<Module>("CloudSync")
    {
        initialize("This module is the CloudSync module.");  // register with Python
    }

    virtual ~Module()
    {}

private:
};

PyObject* initModule()
{
    return Base::Interpreter().addModule(new Module);
}


}  // namespace CloudSync

void slotNewDocument(const App::Document& Doc, bool isMainDoc)
{
    Base::Console().message("CloudSync: new document '{}' (label '{}', main={})\n",
                        Doc.getName(), Doc.Label.getValue(), isMainDoc);
}

/* Python entry */
PyMOD_INIT_FUNC(CloudSync)
{
    App::GetApplication().signalNewDocument.connect(&slotNewDocument);

    PyObject* mod = CloudSync::initModule();
    Base::Console().log("Loading CloudSync module... done\n");
    PyMOD_Return(mod);
}
