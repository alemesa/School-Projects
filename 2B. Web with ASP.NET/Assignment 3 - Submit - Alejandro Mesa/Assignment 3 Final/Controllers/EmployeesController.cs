using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_3_Final.Controllers
{
    public class EmployeesController : Controller
    {
        private Manager m = new Manager();

        // GET: Employees
        public ActionResult Index()
        {

            var c = m.GetAll();


            return View(c);
        }

        // GET: Employees/Details/5
        public ActionResult Details(int? id)
        {

            var o = m.GetOne(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {

                return View(o);
            }
        }

        // GET: Employees/Create
        public ActionResult Create()
        {

            return View();
        }

        // POST: Employees/Create
        [HttpPost]
        public ActionResult Create(EmployeeAdd newItem)
        {

            if (!ModelState.IsValid)
            {

                return View(newItem);
            }


            var addedItem = m.EmployeeAdd(newItem);

            if (addedItem == null)
            {

                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.EmployeeId });
            }
        }

        // GET: Employees/Edit/5
        public ActionResult Edit(int? id)
        {

            var o = m.GetOne(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {

                var editForm = m.mapper.Map<EmployeeBase, EmployeeEditContactInfoForm>(o);

                return View(editForm);
            }
        }

        // POST: Employees/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, EmployeeEditContactInfo newItem)
        {

            if (!ModelState.IsValid)
            {

                return RedirectToAction("edit", new { id = newItem.EmployeeId });
            }

            if (id.GetValueOrDefault() != newItem.EmployeeId)
            {

                return RedirectToAction("index");
            }


            var editedItem = m.EmployeeEditContactInfo(newItem);

            if (editedItem == null)
            {

                return RedirectToAction("edit", new { id = newItem.EmployeeId });
            }
            else
            {
                return RedirectToAction("details", new { id = newItem.EmployeeId });
            }
        }

        // GET: Employees/Delete/5
        public ActionResult Delete(int? id)
        {
            var itemToDelete = m.GetOne(id.GetValueOrDefault());

            if (itemToDelete == null)
            {

                return RedirectToAction("index");
            }
            else
            {
                return View(itemToDelete);
            }
        }

        // POST: Employees/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, FormCollection collection)
        {
            var result = m.EmployeeDelete(id.GetValueOrDefault());
            return RedirectToAction("index");
        }

    }
}
