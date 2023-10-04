#include "step1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
step1App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

step1App::step1App(InputParameters parameters) : MooseApp(parameters)
{
  step1App::registerAll(_factory, _action_factory, _syntax);
}

step1App::~step1App() {}

void 
step1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<step1App>(f, af, s);
  Registry::registerObjectsTo(f, {"step1App"});
  Registry::registerActionsTo(af, {"step1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
step1App::registerApps()
{
  registerApp(step1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
step1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  step1App::registerAll(f, af, s);
}
extern "C" void
step1App__registerApps()
{
  step1App::registerApps();
}
