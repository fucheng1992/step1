//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "step1TestApp.h"
#include "step1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
step1TestApp::validParams()
{
  InputParameters params = step1App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

step1TestApp::step1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  step1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

step1TestApp::~step1TestApp() {}

void
step1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  step1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"step1TestApp"});
    Registry::registerActionsTo(af, {"step1TestApp"});
  }
}

void
step1TestApp::registerApps()
{
  registerApp(step1App);
  registerApp(step1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
step1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  step1TestApp::registerAll(f, af, s);
}
extern "C" void
step1TestApp__registerApps()
{
  step1TestApp::registerApps();
}
