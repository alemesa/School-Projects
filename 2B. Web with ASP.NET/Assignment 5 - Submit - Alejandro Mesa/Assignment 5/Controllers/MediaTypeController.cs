using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class MediaTypeController : Controller
    {
        private Manager m = new Manager();

        // GET: MediaType
        public ActionResult Index()
        {
            var o = m.MediaTypeGetAll();
            return View(o);
        }

        // GET: Album/Details/5
        public ActionResult Details(int id)
        {
            var o = m.MediaTypeGetById(id);

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        // GET: MediaType/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: MediaType/Create
        [HttpPost]
        public ActionResult Create(FormCollection collection)
        {
            try
            {
                // TODO: Add insert logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: MediaType/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: MediaType/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: MediaType/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: MediaType/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
