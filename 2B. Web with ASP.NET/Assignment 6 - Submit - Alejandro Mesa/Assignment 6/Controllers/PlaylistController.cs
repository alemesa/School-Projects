using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_6.Controllers
{
    public class PlaylistController : Controller
    {
        private Manager m = new Manager();

        // GET: Playlist
        public ActionResult Index()
        {
            var p = m.PlaylistGetAll();
            return View(p);
        }

        // GET: Playlist/Details/5
        public ActionResult Details(int id)
        {
            var p = m.PlaylistGetByIdWithDetail(id);
            if (p == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(p);
            }

        }

        // GET: Playlist/Edit/5
        public ActionResult Edit(int id)
        {
            var p = m.PlaylistGetByIdWithDetail(id);
            var selected = p.Tracks.Select(e => e.TrackId);
            if (p == null)
            {
                return HttpNotFound();
            }
            else
            {
                var editForm = m.mapper.Map<PlaylistBase, PlaylistEditTracksForm>(p);
                editForm.TrackList = new MultiSelectList(
                    m.TrackGetAll(),
                    "TrackId",
                    dataTextField: "NameShort",
                    selectedValues: selected);

                List<TrackBase> temporal = new List<TrackBase>();
                foreach (var item in p.Tracks)
                {
                    temporal.Add(item);
                }
                editForm.TrackOnPlaylist = temporal;

                return View(editForm);

            }
        }

        // POST: Playlist/Edit/5
        [HttpPost]
        public ActionResult Edit(int? id, PlaylistEditTracks Collection)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("Edit", new { id = Collection.PlaylistId });
            }
            if (id.GetValueOrDefault() != Collection.PlaylistId)
            {
                
                return RedirectToAction("Index");
            }

            var editedPlaylist = m.PlaylistEdit(Collection);

            if (editedPlaylist == null)
            {
                return RedirectToAction("Edit", new { id = Collection.PlaylistId });
            }
            else
            {
                return RedirectToAction("Details", new { id = Collection.PlaylistId });
            }
        }
    }
}
